#ifndef __APPLY_H__
#define __APPLY_H__

#include "struct.h"

void	apply_top(char** map, int x, int y, t_pos** pos);
void	apply_bottom(char** map, int x, int y, t_pos** pos);
void	apply_left(char** map, int x, int y, t_pos** pos);
void	apply_right(char** map, int x, int y, t_pos** pos);
void	apply_bottom_right(char** map, int x, int y, t_pos** pos);
void	apply_bottom_left(char** map, int x, int y, t_pos** pos);
void	apply_top_right(char** map, int x, int y, t_pos** pos);
void	apply_top_left(char** map, int x, int y, t_pos** pos);
void	apply_click(char** map, int x, int y, t_pos* pos);
#endif
