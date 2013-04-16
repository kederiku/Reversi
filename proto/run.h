#ifndef __CHECK_H__
#define __CHECK_H__

#include <gtk/gtk.h>

char**	init_table();
void	new_button(GtkWidget* table, t_pos** pos, char** map, int* player);
void	get_pos(GtkWidget* widget, gpointer data);
t_pos**	create_pos(void);

#endif
