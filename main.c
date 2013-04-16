#include "proto/window.h"
#include <gtk/gtk.h>

int	main(int argc, char** argv)
{
	(void)argv;
	(void)argc;

	gtk_init(&argc, &argv);
	win_game();
	return 0;
}
