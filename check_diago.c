int	check_top_left(char** map, int x, int y, int player)
{
	if (x <= 0 || y <= 0)
		return -1;
	if (map[y - 1][x - 1] == 0 || map[y - 1][x - 1] == player)
		return -1;
	x = x - 2;
	y = y - 2;
	while (x >= 0 && y >= 0)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x - 1;
		y = y - 1;
	}
	return -1;
}

int	check_top_right(char** map, int x, int y, int player)
{
	if (x > 7 || y <= 0)
		return -1;
	if (map[y - 1][x + 1] == 0 || map[y - 1][x + 1] == player)
		return -1;
	x = x + 2;
	y = y - 2;
	while (x < 7 && y >= 0)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x + 1;
		y = y - 1;
	}
	return -1;
}

int	check_bottom_left(char** map, int x, int y, int player)
{
	if (x <= 0 || y >= 7)
		return -1;
	if (map[y + 1][x - 1] == 0 || map[y + 1][x - 1] == player)
		return -1;
	x = x - 2;
	y = y + 2;
	while (x > 0 && y <= 7)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x - 1;
		y = y + 1;
	}
	return -1;
}

int	check_bottom_right(char** map, int x, int y, int player)
{
	if (x >= 7 || y >= 7)
		return -1;
	if (map[y + 1][x + 1] == 0 || map[y + 1][x + 1] == player)
		return -1;
	x = x + 2;
	y = y + 2;
	while (x < 7 && y < 7)
	{
		if (map[y][x] == 0)
			return -1;
		if (map[y][x] == player)
			return 0;
		x = x + 1;
		y = y + 1;
	}
	return -1;
}
