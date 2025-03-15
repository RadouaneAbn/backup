#include "so_long.h"

void free_map_char(char **simple_map)
{
	int i;

	i = 0;
	while (simple_map[i])
		free(simple_map[i++]);
	free(simple_map);
}