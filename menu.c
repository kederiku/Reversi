#include "proto/window.h"
#include "proto/menu.h"

void	quit(GtkWidget* widget, gpointer data)
{
	(void)widget;
	(void)data;

	gtk_main_quit();
}

void	about(GtkWidget* btn, gpointer data)
{
	(void)btn;
	GtkWidget*	text;

	text = gtk_message_dialog_new(GTK_WINDOW(data), GTK_DIALOG_MODAL,
					GTK_MESSAGE_INFO, GTK_BUTTONS_OK,
					"Reversi by\nGobert_g and Delagr_c");
	gtk_dialog_run(GTK_DIALOG(text));
	gtk_widget_destroy(text);
}

void	create_menu_bar(GtkWidget* vbox, GtkWidget* window)
{
	GtkWidget*	menubar;
	GtkWidget*	menu;
	GtkWidget*	menuitem;

	menubar = gtk_menu_bar_new();
	menu = gtk_menu_new();
	menuitem = gtk_menu_item_new_with_label("New Game");
	gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
	menuitem = gtk_menu_item_new_with_label("Quit");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(quit),
			(GtkWidget*) window);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu),menuitem);
	menuitem = gtk_menu_item_new_with_label("Menu");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);
	menu = gtk_menu_new();
	menuitem = gtk_menu_item_new_with_label("About ...");
	g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(about),
			(GtkWidget*) window);
	gtk_menu_shell_append(GTK_MENU_SHELL(menu), menuitem);
	menuitem = gtk_menu_item_new_with_label("?");
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(menuitem), menu);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), menuitem);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);
}
