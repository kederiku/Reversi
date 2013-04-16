#include "proto/piece.h"
#include "proto/struct.h"
#include <gtk/gtk.h>

void	apply_top_left(char** map, int x, int y, t_pos** pos)
{
	y = y - 1;
	x = x - 1;
	while (map[y][x] != *pos[y][x].player)
	{
		g_signal_handlers_destroy(pos[y][x].area);
		if (*pos[y][x].player == 1)
		{
			color_black(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_black), pos);
			map[y][x] = 1;
		}
		if (*pos[y][x].player == 2)
		{
			color_white(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
			G_CALLBACK(color_white), pos);
			map[y][x] = 2;
		}
		y = y - 1;
		x = x - 1;
	}
}

void	apply_top_right(char** map, int x, int y, t_pos** pos)
{
	y = y - 1;
	x = x + 1;
	while (map[y][x] != *pos[y][x].player)
	{
		g_signal_handlers_destroy(pos[y][x].area);
		if (*pos[y][x].player == 1)
		{
			color_black(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_black), pos);
			map[y][x] = 1;
		}
		else if (*pos[y][x].player == 2)
		{
			color_white(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_white), pos);
			map[y][x] = 2;
		}
		y = y - 1;
		x = x + 1;
	}
}

void	apply_bottom_left(char** map, int x, int y, t_pos** pos)
{
	y = y + 1;
	x = x - 1;
	while (map[y][x] != *pos[y][x].player)
	{
		g_signal_handlers_destroy(pos[y][x].area);
		if (*pos[y][x].player == 1)
		{
			color_black(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_black), pos);
			map[y][x] = 1;
		}
		if (*pos[y][x].player == 2)
		{
			color_white(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_white), pos);
			map[y][x] = 2;
		}
		y = y + 1;
		x = x - 1;
	}
}

void	apply_bottom_right(char** map, int x, int y, t_pos** pos)
{
	y = y + 1;
	x = x + 1;
	while (map[y][x] != *pos[y][x].player)
	{
		g_signal_handlers_destroy(pos[y][x].area);
		if (*pos[y][x].player == 1)
		{
			color_black(pos[y][x].area, 0);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_black), 0);
			map[y][x] = 1;
		}
		if (*pos[y][x].player == 2)
		{
			color_white(pos[y][x].area, 0);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_white), 0);
		map[y][x] = 2;
		}
		y = y + 1;
		x = x + 1;
	}
}
