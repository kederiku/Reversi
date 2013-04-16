#ifndef __CHECK_H__
#define __CHECK_H__

#include <gtk/gtk.h>

int	check_top(char** map, int x, int y, int player);
int	check_bottom(char** map, int x, int y, int player);
int	check_left(char** map, int x, int y, int player);
int	check_right(char** map, int x, int y, int player);
int	check_top_left(char** map, int x, int y, int player);
int	check_top_right(char** map, int x, int y, int player);
int	check_bottom_left(char** map, int x, int y, int player);
int	check_bottom_right(char** map, int x, int y, int player);
int	verify_playable(char** map, int x, int y, int player);

#endif
