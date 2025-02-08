#include "../includes/garbage_collector.h"

void clean_exit(int exit_code)
{
	free_all();
	exit(exit_code);
}
