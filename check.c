#include "proto/check.h"

int	check_top(char** map, int x, int y, int player)
{
	if (y <= 0)
		return -1;
	if (map[y - 1][x] == 0 || map[y - 1][x] == player)
		return -1;
	y = y - 2;
	while (y >= 0)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		y = y - 1;
	}
	return -1;
}

int	check_bottom(char** map, int x, int y, int player)
{
	if (y >= 7)
		return -1;
	if (map[y + 1][x] == 0 || map[y + 1][x] == player)
		return -1;
	y = y + 2;
	while (y <= 7)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		y = y + 1;
	}
	return -1;
}

int	check_left(char** map, int x, int y, int player)
{
	if (x <= 0)
		return -1;
	if (map[y][x - 1] == 0 || map[y][x - 1] == player)
		return -1;
	x = x - 2;
	while (x >= 0)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x - 1;
	}
	return -1;
}

int	check_right(char** map, int x, int y, int player)
{
	if (x >= 7)
		return -1;
	if (map[y][x + 1] == 0 || map[y][x + 1] == player)
		return -1;
	x = x + 2;
	while (x <= 7)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x + 1;
	}
	return -1;
}

int	verify_playable(char** map, int x, int y, int player)
{
	if (map[y][x] != 0)
		return -1;
	if (check_top(map, x, y, player) == 0)
		return 0;
	if (check_bottom(map, x, y, player) == 0)
		return 0;
	if (check_left(map, x, y, player) == 0)
		return 0;
	if (check_right(map, x, y, player) == 0)
		return 0;
	if (check_top_left(map, x, y, player) == 0)
		return 0;
	if (check_top_right(map, x, y, player) == 0)
		return 0;
	if (check_bottom_left(map, x, y, player) == 0)
		return 0;
	if (check_bottom_right(map, x, y, player) == 0)
		return 0;
	return -1;
}
