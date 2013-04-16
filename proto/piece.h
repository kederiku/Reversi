#ifndef __PIECE_H__
#define __PIECE_H__

#include <gtk/gtk.h>
#include "struct.h"

void	color_black(GtkWidget* widget, gpointer data);
void	color_white(GtkWidget* widget, gpointer data);
void	bg(GtkWidget* widget, gpointer data);
void	check_piece(GtkWidget* button, int x, int y, t_pos* pos);

#endif
