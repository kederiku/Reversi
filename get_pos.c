#include "proto/struct.h"
#include "proto/piece.h"
#include "gtk/gtk.h"

void	player_one(GtkWidget* widget, gpointer data)
{
	(void)widget;

	t_pos*	data_gl;

	data_gl = data;
	color_black(data_gl->area, 0);
	g_signal_connect(G_OBJECT(data_gl->area),
			 "expose_event",
			 G_CALLBACK(color_black), 0);
	data_gl->map[data_gl->y][data_gl->x] = 1;
	*data_gl->player = 2;
}

void	player_two(GtkWidget* widget, gpointer data)
{
	(void)widget;

	t_pos*data_gl;

	data_gl = data;
	color_white(data_gl->area, 0);
	g_signal_connect(G_OBJECT(data_gl->area),
			 "expose_event",
			 G_CALLBACK(color_white), 0);
	data_gl->map[data_gl->y][data_gl->x] = 2;
	*data_gl->player = 1;
}
