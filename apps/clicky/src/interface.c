/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_opensocketdialog (void)
{
  GtkWidget *opensocketdialog;
  GtkWidget *dialog_vbox1;
  GtkWidget *table2;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *host;
  GtkWidget *hbox1;
  GtkWidget *port;
  GtkWidget *dialog_action_area1;
  GtkWidget *cancelbutton1;
  GtkWidget *okbutton1;

  opensocketdialog = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (opensocketdialog), _("Open Control Socket"));
  gtk_window_set_position (GTK_WINDOW (opensocketdialog), GTK_WIN_POS_CENTER_ON_PARENT);
  gtk_window_set_modal (GTK_WINDOW (opensocketdialog), TRUE);
  gtk_window_set_skip_taskbar_hint (GTK_WINDOW (opensocketdialog), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (opensocketdialog), GDK_WINDOW_TYPE_HINT_DIALOG);
  gtk_window_set_urgency_hint (GTK_WINDOW (opensocketdialog), TRUE);

  dialog_vbox1 = GTK_DIALOG (opensocketdialog)->vbox;
  gtk_widget_show (dialog_vbox1);

  table2 = gtk_table_new (2, 2, FALSE);
  gtk_widget_show (table2);
  gtk_box_pack_start (GTK_BOX (dialog_vbox1), table2, TRUE, TRUE, 5);
  gtk_table_set_row_spacings (GTK_TABLE (table2), 5);
  gtk_table_set_col_spacings (GTK_TABLE (table2), 5);

  label4 = gtk_label_new (_("Host:"));
  gtk_widget_show (label4);
  gtk_table_attach (GTK_TABLE (table2), label4, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label4), 1, 0.5);

  label5 = gtk_label_new (_("Port:"));
  gtk_widget_show (label5);
  gtk_table_attach (GTK_TABLE (table2), label5, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (label5), 1, 0.5);

  host = gtk_entry_new ();
  gtk_widget_show (host);
  gtk_table_attach (GTK_TABLE (table2), host, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_EXPAND | GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (host), 8226);
  gtk_entry_set_activates_default (GTK_ENTRY (host), TRUE);
  gtk_entry_set_width_chars (GTK_ENTRY (host), 30);

  hbox1 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox1);
  gtk_table_attach (GTK_TABLE (table2), hbox1, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (GTK_FILL), 0, 0);

  port = gtk_entry_new ();
  gtk_widget_show (port);
  gtk_box_pack_start (GTK_BOX (hbox1), port, FALSE, TRUE, 0);
  gtk_entry_set_invisible_char (GTK_ENTRY (port), 8226);
  gtk_entry_set_activates_default (GTK_ENTRY (port), TRUE);
  gtk_entry_set_width_chars (GTK_ENTRY (port), 6);

  dialog_action_area1 = GTK_DIALOG (opensocketdialog)->action_area;
  gtk_widget_show (dialog_action_area1);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_END);

  cancelbutton1 = gtk_button_new_from_stock ("gtk-cancel");
  gtk_widget_show (cancelbutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (opensocketdialog), cancelbutton1, GTK_RESPONSE_CANCEL);
  GTK_WIDGET_SET_FLAGS (cancelbutton1, GTK_CAN_DEFAULT);

  okbutton1 = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton1);
  gtk_dialog_add_action_widget (GTK_DIALOG (opensocketdialog), okbutton1, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton1, GTK_CAN_DEFAULT);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (opensocketdialog, opensocketdialog, "opensocketdialog");
  GLADE_HOOKUP_OBJECT_NO_REF (opensocketdialog, dialog_vbox1, "dialog_vbox1");
  GLADE_HOOKUP_OBJECT (opensocketdialog, table2, "table2");
  GLADE_HOOKUP_OBJECT (opensocketdialog, label4, "label4");
  GLADE_HOOKUP_OBJECT (opensocketdialog, label5, "label5");
  GLADE_HOOKUP_OBJECT (opensocketdialog, host, "host");
  GLADE_HOOKUP_OBJECT (opensocketdialog, hbox1, "hbox1");
  GLADE_HOOKUP_OBJECT (opensocketdialog, port, "port");
  GLADE_HOOKUP_OBJECT_NO_REF (opensocketdialog, dialog_action_area1, "dialog_action_area1");
  GLADE_HOOKUP_OBJECT (opensocketdialog, cancelbutton1, "cancelbutton1");
  GLADE_HOOKUP_OBJECT (opensocketdialog, okbutton1, "okbutton1");

  gtk_widget_grab_default (okbutton1);
  return opensocketdialog;
}

GtkWidget*
create_mainw (void)
{
  GtkWidget *mainw;
  GtkWidget *vbox1;
  GtkWidget *menubar2;
  GtkWidget *menuitem1;
  GtkWidget *menuitem1_menu;
  GtkWidget *menu_new_window;
  GtkWidget *image85;
  GtkWidget *menu_open_file;
  GtkWidget *image86;
  GtkWidget *menu_open_socket;
  GtkWidget *image87;
  GtkWidget *menu_open_kernel;
  GtkWidget *separatormenuitem1;
  GtkWidget *menu_save;
  GtkWidget *menu_save_as;
  GtkWidget *separator1;
  GtkWidget *menu_quit;
  GtkWidget *view1;
  GtkWidget *view1_menu;
  GSList *menu_view_diagram_group = NULL;
  GtkWidget *menu_view_diagram;
  GtkWidget *menu_view_configuration;
  GtkWidget *separator2;
  GtkWidget *menu_view_element;
  GtkWidget *separator3;
  GtkWidget *menu_zoom_in;
  GtkWidget *image88;
  GtkWidget *menu_zoom_out;
  GtkWidget *image89;
  GtkWidget *menu_normal_size;
  GtkWidget *image90;
  GtkWidget *item1;
  GtkWidget *item1_menu;
  GtkWidget *menu_check;
  GtkWidget *image91;
  GtkWidget *menu_install;
  GtkWidget *image92;
  GtkWidget *separator4;
  GtkWidget *item2;
  GtkWidget *item2_menu;
  GSList *menu_config_userlevel_group = NULL;
  GtkWidget *menu_config_userlevel;
  GtkWidget *menu_config_linuxmodule;
  GtkWidget *menu_config_bsdmodule;
  GtkWidget *menu_config_ns;
  GtkWidget *toolbar1;
  GtkIconSize tmp_toolbar_icon_size;
  GtkWidget *tmp_image;
  GtkWidget *toolbar_check;
  GtkWidget *toolbar_install;
  GtkWidget *toolbar_save;
  GtkWidget *toolbar_diagram;
  GtkWidget *throbberitem;
  GtkWidget *throbberbox;
  GtkWidget *throbber;
  GtkWidget *mainhbox;
  GtkWidget *eviewpane;
  GtkWidget *hpaned1;
  GtkWidget *errorpane;
  GtkWidget *errorviewbox;
  GtkWidget *errorviewexpander;
  GtkWidget *label15;
  GtkWidget *errorviewwindow;
  GtkWidget *errorview;
  GtkWidget *elementtreebox;
  GtkWidget *elementtreelabelbox;
  GtkWidget *elementtreelabel;
  GtkWidget *elementtreesort;
  GtkWidget *elementtreeexpander;
  GtkWidget *label16;
  GtkWidget *elementtreewindow;
  GtkWidget *elementtree;
  GtkWidget *vbox7;
  GtkWidget *configwindow;
  GtkWidget *configview;
  GtkWidget *diagramwindow;
  GtkWidget *diagram;
  GtkWidget *eviewbox;
  GtkWidget *eview_titlebox;
  GtkWidget *eview_label;
  GtkWidget *eview_close;
  GtkWidget *image5;
  GtkWidget *eview_refresh;
  GtkWidget *image10;
  GtkWidget *scrolledwindow9;
  GtkWidget *viewport2;
  GtkWidget *vbox6;
  GtkWidget *eview_elementbox;
  GtkWidget *eview_classexpander;
  GtkWidget *label24;
  GtkWidget *eview_class;
  GtkWidget *eview_classinfo;
  GtkWidget *label25;
  GtkWidget *label26;
  GtkWidget *label27;
  GtkWidget *eview_classinfo_ports;
  GtkWidget *eview_classinfo_processing;
  GtkWidget *eview_classinfo_flow;
  GtkWidget *label23;
  GtkWidget *scrolledwindow10;
  GtkWidget *eview_config;
  GtkWidget *eview_handlerbox;
  GtkAccelGroup *accel_group;
  GtkTooltips *tooltips;

  tooltips = gtk_tooltips_new ();

  accel_group = gtk_accel_group_new ();

  mainw = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (mainw, 710, 580);
  gtk_window_set_title (GTK_WINDOW (mainw), _("Clicky"));

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (mainw), vbox1);
  gtk_widget_set_size_request (vbox1, 426, 396);

  menubar2 = gtk_menu_bar_new ();
  gtk_widget_show (menubar2);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar2, FALSE, FALSE, 0);

  menuitem1 = gtk_menu_item_new_with_mnemonic (_("_File"));
  gtk_widget_show (menuitem1);
  gtk_container_add (GTK_CONTAINER (menubar2), menuitem1);

  menuitem1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem1), menuitem1_menu);

  menu_new_window = gtk_image_menu_item_new_with_mnemonic (_("_New Window"));
  gtk_widget_show (menu_new_window);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_new_window);
  gtk_widget_add_accelerator (menu_new_window, "activate", accel_group,
                              GDK_n, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image85 = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image85);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_new_window), image85);

  menu_open_file = gtk_image_menu_item_new_with_mnemonic (_("_Open File..."));
  gtk_widget_show (menu_open_file);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_open_file);
  gtk_widget_add_accelerator (menu_open_file, "activate", accel_group,
                              GDK_o, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image86 = gtk_image_new_from_stock ("gtk-open", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image86);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_open_file), image86);

  menu_open_socket = gtk_image_menu_item_new_with_mnemonic (_("Open Socke_t..."));
  gtk_widget_show (menu_open_socket);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_open_socket);

  image87 = gtk_image_new_from_stock ("gtk-network", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image87);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_open_socket), image87);

  menu_open_kernel = gtk_menu_item_new_with_mnemonic (_("Open _Kernel"));
  gtk_widget_show (menu_open_kernel);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_open_kernel);

  separatormenuitem1 = gtk_separator_menu_item_new ();
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);

  menu_save = gtk_image_menu_item_new_from_stock ("gtk-save", accel_group);
  gtk_widget_show (menu_save);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_save);

  menu_save_as = gtk_image_menu_item_new_from_stock ("gtk-save-as", accel_group);
  gtk_widget_show (menu_save_as);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_save_as);

  separator1 = gtk_separator_menu_item_new ();
  gtk_widget_show (separator1);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), separator1);
  gtk_widget_set_sensitive (separator1, FALSE);

  menu_quit = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  gtk_widget_show (menu_quit);
  gtk_container_add (GTK_CONTAINER (menuitem1_menu), menu_quit);

  view1 = gtk_menu_item_new_with_mnemonic (_("_View"));
  gtk_widget_show (view1);
  gtk_container_add (GTK_CONTAINER (menubar2), view1);

  view1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (view1), view1_menu);

  menu_view_diagram = gtk_radio_menu_item_new_with_mnemonic (menu_view_diagram_group, _("Diagram"));
  menu_view_diagram_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_view_diagram));
  gtk_widget_show (menu_view_diagram);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_view_diagram);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (menu_view_diagram), TRUE);

  menu_view_configuration = gtk_radio_menu_item_new_with_mnemonic (menu_view_diagram_group, _("Configuration"));
  menu_view_diagram_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_view_configuration));
  gtk_widget_show (menu_view_configuration);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_view_configuration);
  gtk_check_menu_item_set_active (GTK_CHECK_MENU_ITEM (menu_view_configuration), TRUE);

  separator2 = gtk_separator_menu_item_new ();
  gtk_widget_show (separator2);
  gtk_container_add (GTK_CONTAINER (view1_menu), separator2);
  gtk_widget_set_sensitive (separator2, FALSE);

  menu_view_element = gtk_check_menu_item_new_with_mnemonic (_("Element"));
  gtk_widget_show (menu_view_element);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_view_element);

  separator3 = gtk_separator_menu_item_new ();
  gtk_widget_show (separator3);
  gtk_container_add (GTK_CONTAINER (view1_menu), separator3);
  gtk_widget_set_sensitive (separator3, FALSE);

  menu_zoom_in = gtk_image_menu_item_new_with_mnemonic (_("Zoom _In"));
  gtk_widget_show (menu_zoom_in);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_zoom_in);
  gtk_widget_add_accelerator (menu_zoom_in, "activate", accel_group,
                              GDK_equal, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);
  gtk_widget_add_accelerator (menu_zoom_in, "activate", accel_group,
                              GDK_plus, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image88 = gtk_image_new_from_stock ("gtk-zoom-in", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image88);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_zoom_in), image88);

  menu_zoom_out = gtk_image_menu_item_new_with_mnemonic (_("Zoom _Out"));
  gtk_widget_show (menu_zoom_out);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_zoom_out);
  gtk_widget_add_accelerator (menu_zoom_out, "activate", accel_group,
                              GDK_minus, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image89 = gtk_image_new_from_stock ("gtk-zoom-out", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image89);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_zoom_out), image89);

  menu_normal_size = gtk_image_menu_item_new_with_mnemonic (_("Normal Size"));
  gtk_widget_show (menu_normal_size);
  gtk_container_add (GTK_CONTAINER (view1_menu), menu_normal_size);

  image90 = gtk_image_new_from_stock ("gtk-zoom-100", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image90);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_normal_size), image90);

  item1 = gtk_menu_item_new_with_mnemonic (_("_Configuration"));
  gtk_widget_show (item1);
  gtk_container_add (GTK_CONTAINER (menubar2), item1);

  item1_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item1), item1_menu);

  menu_check = gtk_image_menu_item_new_with_mnemonic (_("Check for Errors"));
  gtk_widget_show (menu_check);
  gtk_container_add (GTK_CONTAINER (item1_menu), menu_check);
  gtk_widget_add_accelerator (menu_check, "activate", accel_group,
                              GDK_k, (GdkModifierType) GDK_CONTROL_MASK,
                              GTK_ACCEL_VISIBLE);

  image91 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image91);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_check), image91);

  menu_install = gtk_image_menu_item_new_with_mnemonic (_("_Install"));
  gtk_widget_show (menu_install);
  gtk_container_add (GTK_CONTAINER (item1_menu), menu_install);

  image92 = gtk_image_new_from_stock ("gtk-execute", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image92);
  gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (menu_install), image92);

  separator4 = gtk_separator_menu_item_new ();
  gtk_widget_show (separator4);
  gtk_container_add (GTK_CONTAINER (item1_menu), separator4);
  gtk_widget_set_sensitive (separator4, FALSE);

  item2 = gtk_menu_item_new_with_mnemonic (_("Driver"));
  gtk_widget_show (item2);
  gtk_container_add (GTK_CONTAINER (item1_menu), item2);

  item2_menu = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (item2), item2_menu);

  menu_config_userlevel = gtk_radio_menu_item_new_with_mnemonic (menu_config_userlevel_group, _("User-Level"));
  menu_config_userlevel_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_config_userlevel));
  gtk_widget_show (menu_config_userlevel);
  gtk_container_add (GTK_CONTAINER (item2_menu), menu_config_userlevel);

  menu_config_linuxmodule = gtk_radio_menu_item_new_with_mnemonic (menu_config_userlevel_group, _("Linux Kernel"));
  menu_config_userlevel_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_config_linuxmodule));
  gtk_widget_show (menu_config_linuxmodule);
  gtk_container_add (GTK_CONTAINER (item2_menu), menu_config_linuxmodule);

  menu_config_bsdmodule = gtk_radio_menu_item_new_with_mnemonic (menu_config_userlevel_group, _("FreeBSD Kernel"));
  menu_config_userlevel_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_config_bsdmodule));
  gtk_widget_show (menu_config_bsdmodule);
  gtk_container_add (GTK_CONTAINER (item2_menu), menu_config_bsdmodule);

  menu_config_ns = gtk_radio_menu_item_new_with_mnemonic (menu_config_userlevel_group, _("NS Simulator"));
  menu_config_userlevel_group = gtk_radio_menu_item_get_group (GTK_RADIO_MENU_ITEM (menu_config_ns));
  gtk_widget_show (menu_config_ns);
  gtk_container_add (GTK_CONTAINER (item2_menu), menu_config_ns);

  toolbar1 = gtk_toolbar_new ();
  gtk_widget_show (toolbar1);
  gtk_box_pack_start (GTK_BOX (vbox1), toolbar1, FALSE, FALSE, 0);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar1), GTK_TOOLBAR_BOTH);
  tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar1));

  tmp_image = gtk_image_new_from_stock ("gtk-apply", tmp_toolbar_icon_size);
  gtk_widget_show (tmp_image);
  toolbar_check = (GtkWidget*) gtk_tool_button_new (tmp_image, _("Check"));
  gtk_widget_show (toolbar_check);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolbar_check);
  gtk_widget_set_sensitive (toolbar_check, FALSE);

  tmp_image = gtk_image_new_from_stock ("gtk-execute", tmp_toolbar_icon_size);
  gtk_widget_show (tmp_image);
  toolbar_install = (GtkWidget*) gtk_tool_button_new (tmp_image, _("Install"));
  gtk_widget_show (toolbar_install);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolbar_install);
  gtk_widget_set_sensitive (toolbar_install, FALSE);

  toolbar_save = (GtkWidget*) gtk_tool_button_new_from_stock ("gtk-save");
  gtk_widget_show (toolbar_save);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolbar_save);

  toolbar_diagram = (GtkWidget*) gtk_toggle_tool_button_new ();
  gtk_tool_button_set_label (GTK_TOOL_BUTTON (toolbar_diagram), _("Diagram"));
  tmp_image = gtk_image_new_from_stock ("gtk-properties", tmp_toolbar_icon_size);
  gtk_widget_show (tmp_image);
  gtk_tool_button_set_icon_widget (GTK_TOOL_BUTTON (toolbar_diagram), tmp_image);
  gtk_widget_show (toolbar_diagram);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolbar_diagram);

  throbberitem = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (throbberitem);
  gtk_tool_item_set_expand (GTK_TOOL_ITEM (throbberitem), TRUE);
  gtk_container_add (GTK_CONTAINER (toolbar1), throbberitem);

  throbberbox = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (throbberbox);
  gtk_container_add (GTK_CONTAINER (throbberitem), throbberbox);

  throbber = create_pixmap (mainw, NULL);
  gtk_widget_show (throbber);
  gtk_box_pack_end (GTK_BOX (throbberbox), throbber, FALSE, FALSE, 0);
  gtk_misc_set_alignment (GTK_MISC (throbber), 1, 0.5);
  gtk_misc_set_padding (GTK_MISC (throbber), 3, 0);

  mainhbox = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (mainhbox);
  gtk_box_pack_start (GTK_BOX (vbox1), mainhbox, TRUE, TRUE, 2);

  eviewpane = gtk_hpaned_new ();
  gtk_widget_show (eviewpane);
  gtk_box_pack_start (GTK_BOX (mainhbox), eviewpane, TRUE, TRUE, 2);
  gtk_paned_set_position (GTK_PANED (eviewpane), 0);

  hpaned1 = gtk_hpaned_new ();
  gtk_widget_show (hpaned1);
  gtk_paned_pack1 (GTK_PANED (eviewpane), hpaned1, FALSE, TRUE);

  errorpane = gtk_vpaned_new ();
  gtk_widget_show (errorpane);
  gtk_paned_pack1 (GTK_PANED (hpaned1), errorpane, FALSE, TRUE);
  gtk_widget_set_size_request (errorpane, 220, -1);
  gtk_paned_set_position (GTK_PANED (errorpane), 0);

  errorviewbox = gtk_vbox_new (FALSE, 0);
  gtk_paned_pack1 (GTK_PANED (errorpane), errorviewbox, TRUE, FALSE);

  errorviewexpander = gtk_expander_new (NULL);
  gtk_widget_show (errorviewexpander);
  gtk_box_pack_start (GTK_BOX (errorviewbox), errorviewexpander, FALSE, FALSE, 0);
  gtk_expander_set_expanded (GTK_EXPANDER (errorviewexpander), TRUE);

  label15 = gtk_label_new (_("<b>Errors</b>"));
  gtk_widget_show (label15);
  gtk_expander_set_label_widget (GTK_EXPANDER (errorviewexpander), label15);
  gtk_label_set_use_markup (GTK_LABEL (label15), TRUE);

  errorviewwindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (errorviewwindow);
  gtk_box_pack_start (GTK_BOX (errorviewbox), errorviewwindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (errorviewwindow), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (errorviewwindow), GTK_SHADOW_IN);

  errorview = gtk_text_view_new ();
  gtk_widget_show (errorview);
  gtk_container_add (GTK_CONTAINER (errorviewwindow), errorview);
  gtk_text_view_set_editable (GTK_TEXT_VIEW (errorview), FALSE);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (errorview), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (errorview), GTK_WRAP_WORD);
  gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW (errorview), FALSE);

  elementtreebox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (elementtreebox);
  gtk_paned_pack2 (GTK_PANED (errorpane), elementtreebox, TRUE, FALSE);

  elementtreelabelbox = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (elementtreelabelbox);
  gtk_box_pack_start (GTK_BOX (elementtreebox), elementtreelabelbox, FALSE, TRUE, 0);

  elementtreelabel = gtk_label_new (_("<b>List</b>"));
  gtk_widget_show (elementtreelabel);
  gtk_box_pack_start (GTK_BOX (elementtreelabelbox), elementtreelabel, FALSE, TRUE, 0);
  gtk_label_set_use_markup (GTK_LABEL (elementtreelabel), TRUE);
  gtk_misc_set_alignment (GTK_MISC (elementtreelabel), 0, 0.5);
  gtk_misc_set_padding (GTK_MISC (elementtreelabel), 0, 2);

  elementtreesort = gtk_button_new_with_mnemonic (_("Sort: None"));
  gtk_widget_show (elementtreesort);
  gtk_box_pack_end (GTK_BOX (elementtreelabelbox), elementtreesort, FALSE, FALSE, 0);
  gtk_button_set_relief (GTK_BUTTON (elementtreesort), GTK_RELIEF_NONE);
  gtk_button_set_focus_on_click (GTK_BUTTON (elementtreesort), FALSE);

  elementtreeexpander = gtk_expander_new (NULL);
  gtk_box_pack_start (GTK_BOX (elementtreelabelbox), elementtreeexpander, TRUE, TRUE, 0);

  label16 = gtk_label_new (_("<b>List</b>"));
  gtk_widget_show (label16);
  gtk_expander_set_label_widget (GTK_EXPANDER (elementtreeexpander), label16);
  gtk_label_set_use_markup (GTK_LABEL (label16), TRUE);

  elementtreewindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (elementtreewindow);
  gtk_box_pack_start (GTK_BOX (elementtreebox), elementtreewindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (elementtreewindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (elementtreewindow), GTK_SHADOW_IN);

  elementtree = gtk_tree_view_new ();
  gtk_widget_show (elementtree);
  gtk_container_add (GTK_CONTAINER (elementtreewindow), elementtree);
  gtk_widget_set_size_request (elementtree, 200, -1);
  gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (elementtree), FALSE);
  gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (elementtree), TRUE);

  vbox7 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox7);
  gtk_paned_pack2 (GTK_PANED (hpaned1), vbox7, TRUE, TRUE);

  configwindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (configwindow);
  gtk_box_pack_start (GTK_BOX (vbox7), configwindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (configwindow), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (configwindow), GTK_SHADOW_IN);

  configview = gtk_text_view_new ();
  gtk_widget_show (configview);
  gtk_container_add (GTK_CONTAINER (configwindow), configview);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (configview), GTK_WRAP_WORD);

  diagramwindow = gtk_scrolled_window_new (NULL, NULL);
  gtk_box_pack_start (GTK_BOX (vbox7), diagramwindow, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (diagramwindow), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  diagram = gtk_layout_new (NULL, NULL);
  gtk_widget_show (diagram);
  gtk_container_add (GTK_CONTAINER (diagramwindow), diagram);
  gtk_layout_set_size (GTK_LAYOUT (diagram), 400, 400);
  GTK_ADJUSTMENT (GTK_LAYOUT (diagram)->hadjustment)->step_increment = 10;
  GTK_ADJUSTMENT (GTK_LAYOUT (diagram)->vadjustment)->step_increment = 10;

  eviewbox = gtk_vbox_new (FALSE, 0);
  gtk_paned_pack2 (GTK_PANED (eviewpane), eviewbox, FALSE, TRUE);

  eview_titlebox = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (eview_titlebox);
  gtk_box_pack_start (GTK_BOX (eviewbox), eview_titlebox, FALSE, TRUE, 0);

  eview_label = gtk_label_new (_("Element"));
  gtk_widget_show (eview_label);
  gtk_box_pack_start (GTK_BOX (eview_titlebox), eview_label, FALSE, FALSE, 0);

  eview_close = gtk_button_new ();
  gtk_widget_show (eview_close);
  gtk_box_pack_end (GTK_BOX (eview_titlebox), eview_close, FALSE, FALSE, 0);
  gtk_tooltips_set_tip (tooltips, eview_close, _("Close pane"), NULL);
  gtk_button_set_relief (GTK_BUTTON (eview_close), GTK_RELIEF_NONE);
  gtk_button_set_focus_on_click (GTK_BUTTON (eview_close), FALSE);

  image5 = gtk_image_new_from_stock ("gtk-close", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image5);
  gtk_container_add (GTK_CONTAINER (eview_close), image5);

  eview_refresh = gtk_button_new ();
  gtk_box_pack_end (GTK_BOX (eview_titlebox), eview_refresh, FALSE, FALSE, 0);
  gtk_tooltips_set_tip (tooltips, eview_refresh, _("Load handler values"), NULL);
  gtk_button_set_relief (GTK_BUTTON (eview_refresh), GTK_RELIEF_NONE);
  gtk_button_set_focus_on_click (GTK_BUTTON (eview_refresh), FALSE);

  image10 = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_MENU);
  gtk_widget_show (image10);
  gtk_container_add (GTK_CONTAINER (eview_refresh), image10);

  scrolledwindow9 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow9);
  gtk_box_pack_start (GTK_BOX (eviewbox), scrolledwindow9, TRUE, TRUE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow9), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);

  viewport2 = gtk_viewport_new (NULL, NULL);
  gtk_widget_show (viewport2);
  gtk_container_add (GTK_CONTAINER (scrolledwindow9), viewport2);
  gtk_viewport_set_shadow_type (GTK_VIEWPORT (viewport2), GTK_SHADOW_NONE);

  vbox6 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox6);
  gtk_container_add (GTK_CONTAINER (viewport2), vbox6);

  eview_elementbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (eview_elementbox);
  gtk_box_pack_start (GTK_BOX (vbox6), eview_elementbox, FALSE, TRUE, 0);

  eview_classexpander = gtk_expander_new (NULL);
  gtk_widget_show (eview_classexpander);
  gtk_box_pack_start (GTK_BOX (eview_elementbox), eview_classexpander, TRUE, TRUE, 0);

  label24 = gtk_label_new (_("<small>Class</small>"));
  gtk_widget_show (label24);
  gtk_expander_set_label_widget (GTK_EXPANDER (eview_classexpander), label24);
  gtk_label_set_use_markup (GTK_LABEL (label24), TRUE);

  eview_class = gtk_entry_new ();
  gtk_widget_show (eview_class);
  gtk_box_pack_start (GTK_BOX (eview_elementbox), eview_class, FALSE, FALSE, 0);
  GTK_WIDGET_UNSET_FLAGS (eview_class, GTK_CAN_FOCUS);
  gtk_entry_set_invisible_char (GTK_ENTRY (eview_class), 8226);

  eview_classinfo = gtk_table_new (3, 2, FALSE);
  gtk_box_pack_start (GTK_BOX (eview_elementbox), eview_classinfo, TRUE, TRUE, 0);
  gtk_table_set_col_spacings (GTK_TABLE (eview_classinfo), 10);

  label25 = gtk_label_new (_("<small>Ports</small>"));
  gtk_widget_show (label25);
  gtk_table_attach (GTK_TABLE (eview_classinfo), label25, 0, 1, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label25), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label25), 0, 0.5);

  label26 = gtk_label_new (_("<small>Processing</small>"));
  gtk_widget_show (label26);
  gtk_table_attach (GTK_TABLE (eview_classinfo), label26, 0, 1, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label26), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label26), 0, 0.5);

  label27 = gtk_label_new (_("<small>Flow</small>"));
  gtk_widget_show (label27);
  gtk_table_attach (GTK_TABLE (eview_classinfo), label27, 0, 1, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_label_set_use_markup (GTK_LABEL (label27), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label27), 0, 0.5);

  eview_classinfo_ports = gtk_label_new (_("\t"));
  gtk_widget_show (eview_classinfo_ports);
  gtk_table_attach (GTK_TABLE (eview_classinfo), eview_classinfo_ports, 1, 2, 0, 1,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (eview_classinfo_ports), 0, 0.5);

  eview_classinfo_processing = gtk_label_new (_("\t"));
  gtk_widget_show (eview_classinfo_processing);
  gtk_table_attach (GTK_TABLE (eview_classinfo), eview_classinfo_processing, 1, 2, 1, 2,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (eview_classinfo_processing), 0, 0.5);

  eview_classinfo_flow = gtk_label_new (_("\t"));
  gtk_widget_show (eview_classinfo_flow);
  gtk_table_attach (GTK_TABLE (eview_classinfo), eview_classinfo_flow, 1, 2, 2, 3,
                    (GtkAttachOptions) (GTK_FILL),
                    (GtkAttachOptions) (0), 0, 0);
  gtk_misc_set_alignment (GTK_MISC (eview_classinfo_flow), 0, 0.5);

  label23 = gtk_label_new (_("<small>Configuration</small>"));
  gtk_widget_show (label23);
  gtk_box_pack_start (GTK_BOX (eview_elementbox), label23, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label23), TRUE);
  gtk_misc_set_alignment (GTK_MISC (label23), 0, 0.5);

  scrolledwindow10 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow10);
  gtk_box_pack_start (GTK_BOX (eview_elementbox), scrolledwindow10, FALSE, FALSE, 0);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow10), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow10), GTK_SHADOW_IN);

  eview_config = gtk_text_view_new ();
  gtk_widget_show (eview_config);
  gtk_container_add (GTK_CONTAINER (scrolledwindow10), eview_config);
  gtk_text_view_set_accepts_tab (GTK_TEXT_VIEW (eview_config), FALSE);
  gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (eview_config), GTK_WRAP_WORD);

  eview_handlerbox = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (eview_handlerbox);
  gtk_box_pack_start (GTK_BOX (vbox6), eview_handlerbox, FALSE, TRUE, 0);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (mainw, mainw, "mainw");
  GLADE_HOOKUP_OBJECT (mainw, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (mainw, menubar2, "menubar2");
  GLADE_HOOKUP_OBJECT (mainw, menuitem1, "menuitem1");
  GLADE_HOOKUP_OBJECT (mainw, menuitem1_menu, "menuitem1_menu");
  GLADE_HOOKUP_OBJECT (mainw, menu_new_window, "menu_new_window");
  GLADE_HOOKUP_OBJECT (mainw, image85, "image85");
  GLADE_HOOKUP_OBJECT (mainw, menu_open_file, "menu_open_file");
  GLADE_HOOKUP_OBJECT (mainw, image86, "image86");
  GLADE_HOOKUP_OBJECT (mainw, menu_open_socket, "menu_open_socket");
  GLADE_HOOKUP_OBJECT (mainw, image87, "image87");
  GLADE_HOOKUP_OBJECT (mainw, menu_open_kernel, "menu_open_kernel");
  GLADE_HOOKUP_OBJECT (mainw, separatormenuitem1, "separatormenuitem1");
  GLADE_HOOKUP_OBJECT (mainw, menu_save, "menu_save");
  GLADE_HOOKUP_OBJECT (mainw, menu_save_as, "menu_save_as");
  GLADE_HOOKUP_OBJECT (mainw, separator1, "separator1");
  GLADE_HOOKUP_OBJECT (mainw, menu_quit, "menu_quit");
  GLADE_HOOKUP_OBJECT (mainw, view1, "view1");
  GLADE_HOOKUP_OBJECT (mainw, view1_menu, "view1_menu");
  GLADE_HOOKUP_OBJECT (mainw, menu_view_diagram, "menu_view_diagram");
  GLADE_HOOKUP_OBJECT (mainw, menu_view_configuration, "menu_view_configuration");
  GLADE_HOOKUP_OBJECT (mainw, separator2, "separator2");
  GLADE_HOOKUP_OBJECT (mainw, menu_view_element, "menu_view_element");
  GLADE_HOOKUP_OBJECT (mainw, separator3, "separator3");
  GLADE_HOOKUP_OBJECT (mainw, menu_zoom_in, "menu_zoom_in");
  GLADE_HOOKUP_OBJECT (mainw, image88, "image88");
  GLADE_HOOKUP_OBJECT (mainw, menu_zoom_out, "menu_zoom_out");
  GLADE_HOOKUP_OBJECT (mainw, image89, "image89");
  GLADE_HOOKUP_OBJECT (mainw, menu_normal_size, "menu_normal_size");
  GLADE_HOOKUP_OBJECT (mainw, image90, "image90");
  GLADE_HOOKUP_OBJECT (mainw, item1, "item1");
  GLADE_HOOKUP_OBJECT (mainw, item1_menu, "item1_menu");
  GLADE_HOOKUP_OBJECT (mainw, menu_check, "menu_check");
  GLADE_HOOKUP_OBJECT (mainw, image91, "image91");
  GLADE_HOOKUP_OBJECT (mainw, menu_install, "menu_install");
  GLADE_HOOKUP_OBJECT (mainw, image92, "image92");
  GLADE_HOOKUP_OBJECT (mainw, separator4, "separator4");
  GLADE_HOOKUP_OBJECT (mainw, item2, "item2");
  GLADE_HOOKUP_OBJECT (mainw, item2_menu, "item2_menu");
  GLADE_HOOKUP_OBJECT (mainw, menu_config_userlevel, "menu_config_userlevel");
  GLADE_HOOKUP_OBJECT (mainw, menu_config_linuxmodule, "menu_config_linuxmodule");
  GLADE_HOOKUP_OBJECT (mainw, menu_config_bsdmodule, "menu_config_bsdmodule");
  GLADE_HOOKUP_OBJECT (mainw, menu_config_ns, "menu_config_ns");
  GLADE_HOOKUP_OBJECT (mainw, toolbar1, "toolbar1");
  GLADE_HOOKUP_OBJECT (mainw, toolbar_check, "toolbar_check");
  GLADE_HOOKUP_OBJECT (mainw, toolbar_install, "toolbar_install");
  GLADE_HOOKUP_OBJECT (mainw, toolbar_save, "toolbar_save");
  GLADE_HOOKUP_OBJECT (mainw, toolbar_diagram, "toolbar_diagram");
  GLADE_HOOKUP_OBJECT (mainw, throbberitem, "throbberitem");
  GLADE_HOOKUP_OBJECT (mainw, throbberbox, "throbberbox");
  GLADE_HOOKUP_OBJECT (mainw, throbber, "throbber");
  GLADE_HOOKUP_OBJECT (mainw, mainhbox, "mainhbox");
  GLADE_HOOKUP_OBJECT (mainw, eviewpane, "eviewpane");
  GLADE_HOOKUP_OBJECT (mainw, hpaned1, "hpaned1");
  GLADE_HOOKUP_OBJECT (mainw, errorpane, "errorpane");
  GLADE_HOOKUP_OBJECT (mainw, errorviewbox, "errorviewbox");
  GLADE_HOOKUP_OBJECT (mainw, errorviewexpander, "errorviewexpander");
  GLADE_HOOKUP_OBJECT (mainw, label15, "label15");
  GLADE_HOOKUP_OBJECT (mainw, errorviewwindow, "errorviewwindow");
  GLADE_HOOKUP_OBJECT (mainw, errorview, "errorview");
  GLADE_HOOKUP_OBJECT (mainw, elementtreebox, "elementtreebox");
  GLADE_HOOKUP_OBJECT (mainw, elementtreelabelbox, "elementtreelabelbox");
  GLADE_HOOKUP_OBJECT (mainw, elementtreelabel, "elementtreelabel");
  GLADE_HOOKUP_OBJECT (mainw, elementtreesort, "elementtreesort");
  GLADE_HOOKUP_OBJECT (mainw, elementtreeexpander, "elementtreeexpander");
  GLADE_HOOKUP_OBJECT (mainw, label16, "label16");
  GLADE_HOOKUP_OBJECT (mainw, elementtreewindow, "elementtreewindow");
  GLADE_HOOKUP_OBJECT (mainw, elementtree, "elementtree");
  GLADE_HOOKUP_OBJECT (mainw, vbox7, "vbox7");
  GLADE_HOOKUP_OBJECT (mainw, configwindow, "configwindow");
  GLADE_HOOKUP_OBJECT (mainw, configview, "configview");
  GLADE_HOOKUP_OBJECT (mainw, diagramwindow, "diagramwindow");
  GLADE_HOOKUP_OBJECT (mainw, diagram, "diagram");
  GLADE_HOOKUP_OBJECT (mainw, eviewbox, "eviewbox");
  GLADE_HOOKUP_OBJECT (mainw, eview_titlebox, "eview_titlebox");
  GLADE_HOOKUP_OBJECT (mainw, eview_label, "eview_label");
  GLADE_HOOKUP_OBJECT (mainw, eview_close, "eview_close");
  GLADE_HOOKUP_OBJECT (mainw, image5, "image5");
  GLADE_HOOKUP_OBJECT (mainw, eview_refresh, "eview_refresh");
  GLADE_HOOKUP_OBJECT (mainw, image10, "image10");
  GLADE_HOOKUP_OBJECT (mainw, scrolledwindow9, "scrolledwindow9");
  GLADE_HOOKUP_OBJECT (mainw, viewport2, "viewport2");
  GLADE_HOOKUP_OBJECT (mainw, vbox6, "vbox6");
  GLADE_HOOKUP_OBJECT (mainw, eview_elementbox, "eview_elementbox");
  GLADE_HOOKUP_OBJECT (mainw, eview_classexpander, "eview_classexpander");
  GLADE_HOOKUP_OBJECT (mainw, label24, "label24");
  GLADE_HOOKUP_OBJECT (mainw, eview_class, "eview_class");
  GLADE_HOOKUP_OBJECT (mainw, eview_classinfo, "eview_classinfo");
  GLADE_HOOKUP_OBJECT (mainw, label25, "label25");
  GLADE_HOOKUP_OBJECT (mainw, label26, "label26");
  GLADE_HOOKUP_OBJECT (mainw, label27, "label27");
  GLADE_HOOKUP_OBJECT (mainw, eview_classinfo_ports, "eview_classinfo_ports");
  GLADE_HOOKUP_OBJECT (mainw, eview_classinfo_processing, "eview_classinfo_processing");
  GLADE_HOOKUP_OBJECT (mainw, eview_classinfo_flow, "eview_classinfo_flow");
  GLADE_HOOKUP_OBJECT (mainw, label23, "label23");
  GLADE_HOOKUP_OBJECT (mainw, scrolledwindow10, "scrolledwindow10");
  GLADE_HOOKUP_OBJECT (mainw, eview_config, "eview_config");
  GLADE_HOOKUP_OBJECT (mainw, eview_handlerbox, "eview_handlerbox");
  GLADE_HOOKUP_OBJECT_NO_REF (mainw, tooltips, "tooltips");

  gtk_widget_grab_focus (configview);
  gtk_window_add_accel_group (GTK_WINDOW (mainw), accel_group);

  return mainw;
}

