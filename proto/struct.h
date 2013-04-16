#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <gtk/gtk.h>

typedef struct	s_pos
{
	int		x;
	int		y;
	char**		map;
	int*		player;
	GtkWidget*	area;
	struct s_pos**	pos_gl;
}	t_pos;

#endif
