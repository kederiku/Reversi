#ifndef __MENU_H__
#define __MENU_H__

#include <gtk/gtk.h>

void	quit(GtkWidget* widget, gpointer data);
void	about(GtkWidget* btn, gpointer data);
void	create_menu_bar(GtkWidget* vbox, GtkWidget* window);

#endif
