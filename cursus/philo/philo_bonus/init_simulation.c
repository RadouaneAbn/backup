#include "philo_bonus.h"

void remove_sems(t_table *table)
{
	sem_close(table->forks);
	sem_close(table->options.console_sem);
	sem_unlink("/forks");
	sem_unlink("/console_sem");
}

bool create_sems(t_table *table)
{
	// First unlink any existing semaphores
	sem_unlink("/forks");
	sem_unlink("/console_sem");
	
	table->forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, table->options.total_forks);
	table->options.console_sem = sem_open("/console_sem", O_CREAT | O_EXCL, 0644, 1);
	if (table->forks == SEM_FAILED || table->options.console_sem == SEM_FAILED)
	{
		perror("sem_open");
		remove_sems(table);
		return (false);
	}
	table->options.forks = table->forks;
	return (true);
}

int init_simulation(t_table *table)
{
	table->options.sim_running = true;
    if (create_sems(table) == false)
		return (false);
	table->options.start_time = get_current_time() + 100;
	printf("Simulation initialized with start time: %zu\n", table->options.start_time);
	return (true);
}