/*
 * lookupiprouteron.{cc,hh} -- element looks up next-hop address for NAT-RON
 * Alexander Yip
 *
 * Copyright (c) 2001 Massachusetts Institute of Technology
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, subject to the conditions
 * listed in the Click LICENSE file. These conditions include: you must
 * preserve this copyright notice, and you cannot mention the copyright
 * holders in advertising related to the Software without their permission.
 * The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
 * notice is a summary of the Click LICENSE file; the license in that file is
 * legally binding.
 */

#include <click/config.h>
#include "lookupiprouteron.hh"
#include <click/ipaddress.hh>
#include <click/confparse.hh>
#include <click/error.hh>
#include <click/glue.hh>
#include <click/click_tcp.h>
#include <click/string.hh>
#include <click/straccum.hh>

#define rtprintf if(0)printf
#define MEASURE_NATRON 1

LookupIPRouteRON::LookupIPRouteRON() 
  : _expire_timer(expire_hook, (void *) this)
{
  MOD_INC_USE_COUNT;
  add_input();
  _flow_table = new FlowTable();
  _dst_table  = new DstTable();
}

LookupIPRouteRON::~LookupIPRouteRON()
{
  MOD_DEC_USE_COUNT;
  delete(_flow_table);
  delete(_dst_table);
  _expire_timer.unschedule();
}

LookupIPRouteRON *
LookupIPRouteRON::clone() const
{
  return new LookupIPRouteRON;
}

int
LookupIPRouteRON::configure(const Vector<String> &conf, ErrorHandler *errh)
{
  int n = noutputs();
  if (cp_va_parse(conf, this, errh,
		  cpOptional,
		  cpUnsigned, "number of ports", &n,
		  0) < 0)
    return -1;
  if (n < 1)
    return errh->error("number of ports must be at least 1");

  set_noutputs(n+1);
  set_ninputs(n+1);
  return 0;
}

int
LookupIPRouteRON::initialize(ErrorHandler *)
{
  /*
  _last_addr = IPAddress();
#ifdef IP_RT_CACHE2
  _last_addr2 = _last_addr;
#endif
  */
  _expire_timer.initialize(this);
  //_expire_timer.schedule_after_ms(EXPIRE_TIMEOUT_MS);

  return 0;
}

void LookupIPRouteRON::duplicate_pkt(Packet *p) {
  // send <p> out on all outgoing ports except 0

  int n = noutputs();
  for (int i =1; i < n - 1; i++)
    if (Packet *q = p->clone())
      output(i).push(q);
  output(n - 1).push(p);
}

void LookupIPRouteRON::push_forward_syn(Packet *p) 
{
  // what to do in the case of a forward direction syn.
  FlowTableEntry *match = NULL;
  FlowTableEntry *new_entry = NULL;
  DstTableEntry  *dst_match = NULL;
  const click_ip  *iph = p->ip_header();
  const click_tcp *tcph= p->tcp_header();
  unsigned tcp_seq = ntohl(tcph->th_seq) + 
    ntohs(iph->ip_len) - (iph->ip_hl << 2) - (tcph->th_off << 2)+1;
  //click_chatter("syn seq: %u\n", tcp_seq);

  //gettimeofday(&tp, NULL);
  //click_chatter("SAWSYN: (%ld,%ld)", tp.tv_sec, tp.tv_usec);
  print_time("SAWSYN:");

  tcph = p->tcp_header();

  match = _flow_table->lookup(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(),
			      ntohs(tcph->th_sport), ntohs(tcph->th_dport));
  
  rtprintf ("FOR TCP SYN\n");
  //fflush(NULL);

  if (match) {
    // Match found
    match->saw_forward_packet();
    
    if (match->is_pending()){
      rtprintf("FLOW match(pending), send PROBE\n");
      match->outstanding_syns++;
      duplicate_pkt(p);
    } else {
      // this can happen if an identical flow is started before the last one
      // was removed from the flow table.
      click_chatter("FLOW match, port (%d) {%s}->{%s}", 
	     match->outgoing_port,
	     IPAddress(p->ip_header()->ip_src).s().cc(), 
	     p->dst_ip_anno().s().cc());
      //fflush(NULL);
      output(match->outgoing_port).push(p);
      return;
    }    
  } else {
    // NO match, Look into Dst Table
    dst_match = _dst_table->lookup(p->dst_ip_anno());

    // Add new entry to Flow Table
    new_entry = _flow_table->add(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(),
				 ntohs(tcph->th_sport), ntohs(tcph->th_dport),
				 click_jiffies(),tcp_seq);
    new_entry->saw_forward_packet();
    
    if (dst_match){
      new_entry->outgoing_port = dst_match->outgoing_port;
      click_chatter("DST match, port (%d) {%s}->{%s}", 
	     new_entry->outgoing_port,
	     IPAddress(p->ip_header()->ip_src).s().cc(), 
	     p->dst_ip_anno().s().cc() );
      //fflush(NULL);
      output(new_entry->outgoing_port).push(p);
      return;

    } else {
      rtprintf("DST nomatch, send PROBE\n");
      new_entry->outgoing_port = 0;
      new_entry->outstanding_syns++;
      duplicate_pkt(p);
    }
  }
  
  return;
}
void LookupIPRouteRON::push_forward_fin(Packet *p) 
{
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;

  tcph = p->tcp_header();
  
  rtprintf("FOR TCP FIN\n");

  match = _flow_table->lookup(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(),
			      ntohs(tcph->th_sport), ntohs(tcph->th_dport));
  if (match) {
    if (!match->is_pending()) {
      rtprintf(" found non-pending match, ending forward connection\n");
      match->saw_forward_packet();
      match->forw_alive = 0; // forward flow is over
      output(match->outgoing_port).push(p);
      return;
    } 
  }
  rtprintf(" could not find non-pending match, killing pkt.\n");
  p->kill();
  return;
}

void LookupIPRouteRON::push_forward_rst(Packet *p) 
{
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;

  tcph = p->tcp_header();
  rtprintf("FOR TCP RST\n");

  match = _flow_table->lookup(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(),
			      ntohs(tcph->th_sport), ntohs(tcph->th_dport));
  
  if (match) {
    if (!match->is_pending()) {
      rtprintf("found match, non-pending, forwarding...\n");
      match->saw_forward_packet();
      match->forw_alive = 0; // forward & reverse flows are over
      match->rev_alive = 0; 
      output(match->outgoing_port).push(p);
      return;
    }
  }
  
  rtprintf("could not find non-pending match. Killing packet\n");
  p->kill();
}

void LookupIPRouteRON::push_forward_normal(Packet *p) 
{
  // what to do in the case of a forward direction syn.
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;

  tcph = p->tcp_header();

  rtprintf("FOR TCP normal pkt\n");

  match = _flow_table->lookup(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(),
			      ntohs(tcph->th_sport), ntohs(tcph->th_dport));
  
  if (match) {
    if (!match->is_pending()) {
      rtprintf("found match, not pending, forwarding...\n");
      match->saw_forward_packet();
      output(match->outgoing_port).push(p);
      return;
    }
  }
  
  rtprintf("could not find non-pending match. Killing packet\n");
  p->kill();

}

void LookupIPRouteRON::push_forward_packet(Packet *p) 
{
  const click_tcp *tcph;

  // if non-TCP just forward direct 
  // (YIPAL: perhaps this could be more intelligent)
  if (p->ip_header()->ip_p != IP_PROTO_TCP) {
    rtprintf("non-TCP proto(%d)\n", p->ip_header()->ip_p);
    output(1).push(p);
    return;
  }

  // Switch on TCP packet type
  tcph = p->tcp_header();
  if (tcph->th_flags & TH_SYN) {
    push_forward_syn(p);
  } else if (tcph->th_flags & TH_FIN) {
    push_forward_fin(p);
  } else if (tcph->th_flags & TH_RST) {
    push_forward_rst(p);
  } else {
    push_forward_normal(p);
  }
  return;
}

void LookupIPRouteRON::push_reverse_synack(unsigned inport, Packet *p) 
{
#if MEASURE_NATRON
  unsigned int portno;
#endif

  char buf[128];
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;
  tcph = p->tcp_header();

  //gettimeofday(&tp, NULL);

  match = _flow_table->lookup(p->dst_ip_anno(),IPAddress(p->ip_header()->ip_src),
			      ntohs(tcph->th_dport), ntohs(tcph->th_sport));
  
  //click_chatter("REV TCP SYN-ACK inport(%d) (%ld,%ld)", inport,tp.tv_sec, tp.tv_usec);
  sprintf(buf, "REV TCP SYN-ACK inport(%d)", inport);
  print_time(buf);
  
  if (match) { 
    match->saw_reply_packet();
    
    if (match->is_pending()) {
      click_chatter("FLOW match(pending), port(%d) {%s}->{%s}", 
	     inport, 
	     p->dst_ip_anno().s().cc(), 
	     IPAddress(p->ip_header()->ip_src).s().cc() );
      //fflush(NULL);

#if MEASURE_NATRON
      portno = 1+ (unsigned int) (((float)(random() & 0xff)/256) * (noutputs()-1) );
      portno = 2;
      click_chatter("Choosing(%d)", portno);
      // dont save to dst_table
      // _dst_table->insert(IPAddress(p->ip_header()->ip_src), portno); 

      // remember which port the first syn-ack came back on
      match->outgoing_port = portno;
      match->outstanding_syns = 0;

      if (portno == inport)
	output(0).push(p);
      else {
	// send RST to first replier
	send_rst(p, match, inport);
      }

      return;
#else
      // save to dst_table
      _dst_table->insert(IPAddress(p->ip_header()->ip_src), inport); 
      // remember which port the first syn-ack came back on
      match->outgoing_port = inport;

      match->outstanding_syns = 0;
      output(0).push(p);
      return;
#endif

    } else {
      // FLOW not pending
      if (inport == match->outgoing_port){
	rtprintf("Correct return port, forwarding reverse SYN-ACK\n");
	output(0).push(p);
	return;
      } else {
	rtprintf("Incorrect return port, replying with RST\n");
	send_rst(p, match, inport);
	return;
      }    

    }
  } else {
    rtprintf("FLOW no match, killing SYN-ACK\n");
    p->kill();
  }

}
void LookupIPRouteRON::push_reverse_fin(Packet *p) 
{
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;
  tcph = p->tcp_header();

  match = _flow_table->lookup(p->dst_ip_anno(),IPAddress(p->ip_header()->ip_src),
			      ntohs(tcph->th_dport), ntohs(tcph->th_sport));
  
  rtprintf("REV TCP FIN\n");

  if (match) {
    if (!match->is_pending()) {
      rtprintf(" found match, not pending, ending reverse direction\n");
      match->saw_reply_packet();
      match->rev_alive = 0;
      output(0).push(p);
      return;
    }
  }

  rtprintf(" could not find non-pending match. Killing pkt.\n");
  p->kill();
}
void LookupIPRouteRON::push_reverse_rst(Packet *p) 
{
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;
  tcph = p->tcp_header();
  match = _flow_table->lookup(p->dst_ip_anno(),IPAddress(p->ip_header()->ip_src),
			      ntohs(tcph->th_dport), ntohs(tcph->th_sport));
  
  rtprintf("REV TCP RST\n");

  if (match) {
    if (!match->is_pending()) {
      rtprintf(" found match, not pending, ending reverse direction\n");
      match->saw_reply_packet();
      match->forw_alive = 0;
      match->rev_alive = 0;
      output(0).push(p);
      return;
    }
  }

  rtprintf(" could not find non-pending match. Killing pkt.\n");
  p->kill();
}
void LookupIPRouteRON::push_reverse_normal(Packet *p) 
{
  const click_tcp *tcph;
  FlowTableEntry *match = NULL;
  tcph = p->tcp_header();
 
  match = _flow_table->lookup(p->dst_ip_anno(),IPAddress(p->ip_header()->ip_src),
			      ntohs(tcph->th_dport), ntohs(tcph->th_sport));

  rtprintf("REV TCP normal pkt\n");

  if (match) {
    if (!match->is_pending()) {
      rtprintf("found match, not pending, forwarding...\n");
      match->saw_reply_packet();
      output(0).push(p);
      return;
    }
  }
  
  rtprintf("could not find non-pending match. Killing packet\n");
  p->kill();
}


void LookupIPRouteRON::push_reverse_packet(int inport, Packet *p) 
{
  const click_tcp *tcph;

  // if non-TCP just forward direct 
  // (YIPAL: perhaps this could be more intelligent)
  if (p->ip_header()->ip_p != IP_PROTO_TCP) {
    rtprintf("non-TCP proto(%d)\n", p->ip_header()->ip_p);
    output(0).push(p);
    return;
  }

  // Switch on TCP packet type
  tcph = p->tcp_header();
  if ((tcph->th_flags & TH_SYN) && (tcph->th_flags & TH_ACK)) {
    push_reverse_synack(inport, p);
  } else if (tcph->th_flags & TH_FIN) {
    push_reverse_fin(p);
  } else if (tcph->th_flags & TH_RST) {
    push_reverse_rst(p);
  } else {
    push_reverse_normal(p);
  }
  return;
}

void
LookupIPRouteRON::push(int inport, Packet *p)
{
  //click_tcp *tcph;
  //FlowTableEntry *e;
  //int matchState;

  if (inport == 0) {
    push_forward_packet(p);
  } else {
    push_reverse_packet(inport, p);
  }

  /*
  //// ---- TEST CODE -----  
  rtprintf("adding address to table(%u): \n", click_jiffies());
  tcph = p->tcp_header();
  
  _t->add(IPAddress(p->ip_header()->ip_src), p->dst_ip_anno(), 
	  ntohs(tcph->th_sport), ntohs(tcph->th_dport), 10, 
	  11, 12, click_jiffies(), 1, 1, 1);

  _t->print();
  //_t->del(IPAddress("1.1.1.1"));
  //_t->print();  
  matchState = _t->lookup(IPAddress("18.7.0.12"), IPAddress("18.239.0.139"), 
			  80, 1410, &e);
  
  if (e)
    rtprintf("match type(%d) ports %u -> %u\n",matchState, e->sport, e->dport);
  else
    rtprintf("no match\n");
  */

  
#ifdef 0
  _flow_table->print();  
  _dst_table->print();
  rtprintf("\n");
#endif
}

void LookupIPRouteRON::send_rst(Packet *p, FlowTableEntry *match, int outport) {
  WritablePacket *rst_pkt;
  click_ip *iphdr;
  click_tcp *tcphdr;

  rst_pkt = WritablePacket::make(40);
  rst_pkt->set_network_header(rst_pkt->data(), 20);
  iphdr  = rst_pkt->ip_header();
  tcphdr = rst_pkt->tcp_header();

  tcphdr->th_sport = p->tcp_header()->th_dport;	
  tcphdr->th_dport = p->tcp_header()->th_sport;
  tcphdr->th_seq   = htonl(match->syn_seq);
  tcphdr->th_ack   = htonl(ntohl(p->tcp_header()->th_seq) + 1);
  tcphdr->th_off   = 5;
  tcphdr->th_flags  = TH_RST | TH_ACK;
  tcphdr->th_win   = ntohs(16384);
  tcphdr->th_urp   = 0;
  tcphdr->th_sum   = 0;
	
  memset(iphdr, '\0', 9);
  iphdr->ip_sum = 0;
  iphdr->ip_len = htons(20);
  iphdr->ip_p   = IP_PROTO_TCP;
  iphdr->ip_src = p->ip_header()->ip_dst;
  iphdr->ip_dst = p->ip_header()->ip_src;

  //set tcp checksum
  tcphdr->th_sum = click_in_cksum((unsigned char *)iphdr, 40);
  iphdr->ip_len = htons(40);

  iphdr->ip_v   = 4;
  iphdr->ip_hl  = 5;
  iphdr->ip_id  = htons(0x1234);
  iphdr->ip_off = 0; 
  iphdr->ip_ttl = 32;
  iphdr->ip_sum = 0;

  // set ip checksum
  iphdr->ip_sum = click_in_cksum(rst_pkt->data(), 20);

  p->kill();
  output(outport).push(rst_pkt);
  return;
}

void LookupIPRouteRON::expire_hook(Timer *, void *thunk) 
{
  /*
  Packet *p;
  Vector<FlowTableEntry*> syn_waiting;
  LookupIPRouteRON *rt = (LookupIPRouteRON *) thunk;
  */
}

static String
read_handler(Element *, void *)
{
  return "false\n";
}

void
LookupIPRouteRON::add_handlers()
{
  // needed for QuitWatcher
  add_read_handler("scheduled", read_handler, 0);
}



// ------ FlowTable methods -------
LookupIPRouteRON::FlowTable::FlowTable() {
  _last_entry = NULL;

}

LookupIPRouteRON::FlowTable::~FlowTable() {
}

LookupIPRouteRON::FlowTableEntry *
LookupIPRouteRON::FlowTable::lookup(IPAddress src, IPAddress dst,
				    unsigned short sport, unsigned short dport){
  rtprintf("LOOKUP: %d.%d.%d.%d(%d) -> %d.%d.%d.%d(%d)\n",
	   src.data()[0], src.data()[1], src.data()[2], src.data()[3], sport,
	   dst.data()[0], dst.data()[1], dst.data()[2], dst.data()[3], dport);

  // check cache first
  if (_last_entry && _last_entry->is_valid() && 
      (_last_entry->src   == src) && 
      (_last_entry->dst   == dst) && 
      (_last_entry->sport == sport) && 
      (_last_entry->dport == dport)) {
    return _last_entry;
  }

  // find a valid match
  for (int i = 0; i < _v.size(); i++){
    
    if (_v[i].is_valid() && 
	(src == _v[i].src) && (dst == _v[i].dst) && 
	(sport == _v[i].sport) && (dport == _v[i].dport)) {

	// exact match is found
      _last_entry = &_v[i]; // cache this match
      return &_v[i];
    }
  }
  // no match found
  return 0;
}

LookupIPRouteRON::FlowTableEntry*
LookupIPRouteRON::FlowTable::add(IPAddress src, IPAddress dst, 
				 unsigned short sport, unsigned short dport, 
				 unsigned probe_time, unsigned syn_seq) {

  FlowTableEntry e;
  e.src = src;
  e.dst = dst;
  e.sport = sport;
  e.dport = dport;
  e.outgoing_port = 0;
  e.oldest_unanswered = 0;
  e.last_reply = 0; 
  e.forw_alive = 1;
  e.rev_alive = 1;
  e.outstanding_syns = 0;
  e.probe_time = probe_time;
  e.syn_seq = syn_seq;
  //e.clear_waiting();

  // replace duplicate entry first
  for (int i = 0; i < _v.size(); i++)
    if ((src == _v[i].src) && (dst == _v[i].dst) && 
	(sport == _v[i].sport) && (dport == _v[i].dport)) {
      _v[i] = e;
      rtprintf("  replacing existing entry in table\n");
      return &_v[i];
    }

  // replace invalid entries
  for (int i = 0; i < _v.size(); i++)
    if (!_v[i].is_valid() || (!_v[i].is_active() && _v[i].is_old()) ) {
      _v[i] = e;
      rtprintf("  replacing invalid entry in table\n");
      return &_v[i];
    }

  // just push new entry onto back of table.
  rtprintf("  adding new entry to table\n");
  _v.push_back(e);
  return &_v[_v.size()-1];

}

void 
LookupIPRouteRON::FlowTable::del(IPAddress src, IPAddress dst, 
				 unsigned short sport, unsigned short dport){
  // find a match
  for (int i = 0; i < _v.size(); i++){
    
    if ( (src == _v[i].src) && (dst == _v[i].dst) && 
	 (sport == _v[i].sport) && (dport == _v[i].dport)) {
      // exact match is found
      _v[i].dst = IPAddress(1);
      _v[i].forw_alive = 0;
      _v[i].rev_alive  = 0;
      _v[i].invalidate(); // this "deletes" the entry
      return;
    }
  }
}

void
LookupIPRouteRON::FlowTable::print() {
  rtprintf("  Table contents size(%d):\n", _v.size());
  for (int i = 0; i < _v.size(); i++) {
    if (_v[i].is_valid()) {
      //rtprintf( "    [%d] %02x%02x%02x%02x(%u) -> %02x%02x%02x%02x(%u) ",
      rtprintf( "    [%d] %d.%d.%d.%d(%u) -> %d.%d.%d.%d(%u) \t",
	      //_v[i].get_state(),
	      0,
	      _v[i].src.data()[0],_v[i].src.data()[1], 
	      _v[i].src.data()[2],_v[i].src.data()[3],
	      _v[i].sport,

	      _v[i].dst.data()[0],_v[i].dst.data()[1], 
	      _v[i].dst.data()[2],_v[i].dst.data()[3],
	      _v[i].dport);
      rtprintf("outport(%d) pending(%d) waiting(%d) \tage(%u) FR = %d%d\n", 
	     _v[i].outgoing_port, _v[i].outstanding_syns,
	     //_v[i].waiting.size(), 
	     0,
	     _v[i].get_age(), 	     
	     _v[i].forw_alive, _v[i].rev_alive);

      //if (_v[i].get_state() == FlowTableEntry::INVALID) exit(0);
    }
  }
}

LookupIPRouteRON::DstTable::DstTable() {
  _last_entry = NULL;
}
LookupIPRouteRON::DstTable::~DstTable() {
}

LookupIPRouteRON::DstTableEntry*
LookupIPRouteRON::DstTable::lookup(IPAddress dst) {

  // check cache first.
  if (_last_entry && 
      _last_entry->is_valid() &&
      _last_entry->is_recent() &&
      _last_entry->dst == dst) {
    return _last_entry;
  }

  // search
  for(int i=0; i<_v.size(); i++) {
    if (_v[i].is_valid() &&
	_v[i].is_recent() &&
	_v[i].dst == dst) {
      
      _last_entry = &_v[i]; // cache last match
      return &_v[i];
    }
  }
  return 0;
}

void
LookupIPRouteRON::DstTable::insert(IPAddress dst, unsigned short assigned_port) {
  int replaceme = -1;
  
  DstTableEntry e;

  for(int i=0; i<_v.size(); i++) {
    if (_v[i].dst == dst) {
      _v[i].outgoing_port = assigned_port;
      _v[i].probe_time = click_jiffies();
      return;
    }
    if (!_v[i].is_recent()) {
      replaceme = i;
    }
  }
  
  if (replaceme != -1) {
      _v[replaceme].dst = dst;
      _v[replaceme].outgoing_port = assigned_port;
      _v[replaceme].probe_time = click_jiffies();
      return;
  }
  
  e.dst = dst;
  e.outgoing_port = assigned_port;
  e.probe_time = click_jiffies();
  _v.push_back(e);
  return;
}

void
LookupIPRouteRON::DstTable::print() {
  rtprintf("DST Table Contents(%d)\n", _v.size());
  for(int i=0; i<_v.size(); i++) {
    rtprintf("  %d.%d.%d.%d \t port(%d) valid(%d) recent(%d)\n", 
	     _v[i].dst.data()[0], _v[i].dst.data()[1], 
	     _v[i].dst.data()[2], _v[i].dst.data()[3], 
	     _v[i].outgoing_port, _v[i].is_valid(), _v[i].is_recent());
  }
}

void LookupIPRouteRON::print_time(char* s) {
  struct timeval tp;
  gettimeofday(&tp, NULL);
  click_chatter("%s (%ld,%ld)", s, tp.tv_sec, tp.tv_usec);
}


// generate Vector template instance
#include <click/vector.cc>
// must always generate the whole instance! LookupIPRoute demands it
template class Vector<LookupIPRouteRON::FlowTableEntry>;


EXPORT_ELEMENT(LookupIPRouteRON)
