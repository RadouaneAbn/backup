#include "philo.h"

void print_table(t_table *table)
{
	int i;

	printf("Philos:		%d\n", table->options.total_philos);
	printf("Forks:		%d\n", table->options.total_philos);
	printf("Time2die:	%d\n", table->options.time2die);
	printf("Time2eat:	%d\n", table->options.time2eat);
	printf("Time2sleep:	%d\n", table->options.time2sleep);
	printf("Max meals:	%d\n", table->options.max_meals);

	i = 0;
	printf("\nPhilos:\n");
	while (i < table->options.total_philos)
	{
		printf("    Philo { id: %d }\n",
			table->philos[i].id);
		i++;
	}
}