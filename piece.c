#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "proto/struct.h"

void	color_black(GtkWidget* widget, gpointer data)
{
	(void)data;
	GdkGC*		gc;
	GdkColor	color;

	gc = gdk_gc_new(widget->window);
	color.blue = 0;
	color.red = 0;
	color.green = 0;
	gdk_gc_set_rgb_fg_color(gc, &color);
	gdk_draw_arc(widget->window, gc, TRUE, 0, 0, widget->allocation.width,
		     widget->allocation.height, 0, 64 * 360);
}

void	color_white(GtkWidget* widget, gpointer data)
{
	(void)data;
	GdkGC*		gc;
	GdkColor	color;

	gc = gdk_gc_new(widget->window);
	color.blue = 65000;
	color.red = 65000;
	color.green = 65000;
	gdk_gc_set_rgb_fg_color(gc, &color);
	gdk_draw_arc(widget->window, gc, TRUE, 0, 0, widget->allocation.width,
		     widget->allocation.height, 0, 64 * 360);
}

void	check_piece(GtkWidget* button, int x, int y, t_pos* pos)
{
	pos->area = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(button), pos->area);
	if (pos->map[y][x] == 2)
		g_signal_connect(G_OBJECT(pos->area), "expose_event",
				 G_CALLBACK(color_white), pos);
	else if (pos->map[y][x] == 1)
		g_signal_connect(G_OBJECT(pos->area), "expose_event",
				 G_CALLBACK(color_black), pos);
}
