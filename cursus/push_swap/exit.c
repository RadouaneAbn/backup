#include "defs.h"

void	clean_exit(void *p1, void *p2, void *p3, void *p4)
{
	if (p1)
		free(p1);
	if (p2)
		free(p2);
	if (p3)
		free(p3);
	if (p4)
		free(p4);
	write(1, "Error\n", 7);
	// exit(1);
}