#include <gtk/gtk.h>
#include "proto/free.h"
#include "proto/menu.h"
#include "proto/run.h"

void	win_game()
{
	GtkWidget*	table;
	GtkWidget*	window;
	GtkWidget*	vbox;
	char**		map;
	int		player;
	t_pos**		pos;

	player = 1;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Reversi");
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(quit), 0);
	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);
	create_menu_bar(vbox, window);
	table = gtk_table_new(8, 8, TRUE);
	gtk_container_add(GTK_CONTAINER(vbox), table);
	map = init_table();
	pos = create_pos();
	new_button(table, pos, map, &player);
	gtk_widget_show_all(window);
	gtk_main();
	free_pos(pos);
	free_table(map);
}
