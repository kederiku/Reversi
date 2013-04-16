#include <stdlib.h>
#include "proto/struct.h"

void	free_table(char** table)
{
	int	 y;

	y = 0;
	while (y < 8)
	{
		free(table[y]);
		y = y + 1;
	}
	free(table);
}

void	free_pos(t_pos** pos)
{
	int	 y;

	y = 0;
	while (y < 8)
	{
		free(pos[y]);
		y = y + 1;
	}
	free(pos);
}
