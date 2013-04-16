#include <gtk/gtk.h>
#include <stdlib.h>
#include "proto/check.h"
#include "proto/apply.h"
#include "proto/struct.h"
#include "proto/piece.h"
#include "proto/get_pos.h"

char**	init_table()
{
	char**	map;
	int	x;
	int	y;

	if ((map = malloc(sizeof(*map) * 8)) == 0)
		return 0;
	y = 0;
	while (y < 8)
	{
		if ((map[y] = malloc((sizeof(*map[y])) * 8)) == 0)
			return 0;
		x = 0;
		while (x < 8)
		{
			map[y][x] = 0;
			x = x + 1;
		}
		y = y + 1;
	}
	map[3][4] = 1;
	map[4][3] = 1;
	map[3][3] = 2;
	map[4][4] = 2;
	return map;
}

void	get_pos(GtkWidget* widget, gpointer data)
{
	(void)widget;

	t_pos*	data_gl;
	int	ret;

	data_gl = data;
	ret = verify_playable(data_gl->map, data_gl->x, data_gl->y,
			      *data_gl->player);
	if (ret == 0)
	{
		apply_click(data_gl->map, data_gl->x, data_gl->y, data_gl);
		if (*data_gl->player == 1)

			player_one(widget, data);
		else
			player_two(widget, data);
	}
}

void	new_button(GtkWidget* table, t_pos** pos, char** map, int* player)
{
	GtkWidget*	button;
	int		x;
	int		y;

	y = 0;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			button = gtk_button_new();
			pos[y][x].x = x;
			pos[y][x].y = y;
			pos[y][x].map = map;
			pos[y][x].player = player;
			pos[y][x].pos_gl = pos;
			gtk_table_attach_defaults(GTK_TABLE(table), button, x,
						  x + 1, y, y + 1);
			g_signal_connect(G_OBJECT(button), "clicked",
					 G_CALLBACK(get_pos), &(pos[y][x]));
			check_piece(button, x, y, &pos[y][x]);
			x = x + 1;
		}
		y = y + 1;
	}
}

t_pos**	create_pos()
{
	t_pos** pos;
	int	y;

	if ((pos = malloc(sizeof(*pos) * 8)) == 0)
		return 0;
	y = 0;
	while (y < 8)
	{
		if ((pos[y] = malloc(sizeof(*pos[y]) * 8)) == 0)
			return 0;
		y = y + 1;
	}
	return pos;
}
