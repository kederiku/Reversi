#include <gtk/gtk.h>
#include "proto/apply.h"
#include "proto/check.h"
#include "proto/piece.h"

void	apply_top(char** map, int x, int y, t_pos** pos)
{
	y = y - 1;
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
		y = y - 1;
	}
}

void	apply_bottom(char** map, int x, int y, t_pos** pos)
{
	y = y + 1;
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
	}
}

void	apply_left(char** map, int x, int y, t_pos** pos)
{
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
		x = x - 1;
	}
}

void	apply_right(char** map, int x, int y, t_pos** pos)
{
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
		if (*pos[y][x].player == 2)
		{
			color_white(pos[y][x].area, pos);
			g_signal_connect(G_OBJECT(pos[y][x].area),
					 "expose_event",
					 G_CALLBACK(color_white), pos);
			map[y][x] = 2;
		}
		x = x + 1;
	}
}
void	apply_click(char** map, int x, int y, t_pos* pos)
{
	if (check_top(map, x, y, *pos->player) == 0)
		apply_top(map, x, y, pos->pos_gl);
	if (check_bottom(map, x, y, *pos->player) == 0)
		apply_bottom(map, x, y, pos->pos_gl);
	if (check_left(map, x, y, *pos->player) == 0)
		apply_left(map, x, y, pos->pos_gl);
	if (check_right(map, x, y, *pos->player) == 0)
		apply_right(map, x, y, pos->pos_gl);
	if (check_top_left(map, x, y, *pos->player) == 0)
		apply_top_left(map, x, y, pos->pos_gl);
	if (check_top_right(map, x, y, *pos->player) == 0)
		apply_top_right(map, x, y, pos->pos_gl);
	if (check_bottom_left(map, x, y, *pos->player) == 0)
		apply_bottom_left(map, x, y, pos->pos_gl);
	if (check_bottom_right(map, x, y, *pos->player) == 0)
		apply_bottom_right(map, x, y, pos->pos_gl);
}
