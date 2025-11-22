#include "philo.h"

bool check_philo_status(t_table *table)
{
	int i;

	i = 0;
	while (i < table->options.total_philos)
	{
		if (philo_is_alive(&(table->philos[i])) == false)
		{
			stop_sim(table);
			print_death_message(&(table->philos[i]));
			return (false);
		}
		i++;
	}
	return (true);
}

bool check_philo_status_and_count_meals(t_table *table)
{
	int i;
	bool all_philos_has_eaten;

	i = 0;
	all_philos_has_eaten = true;
	while (i < table->options.total_philos)
	{
		if (philo_is_alive(&(table->philos[i])) == false)
		{
			stop_sim(table);
			print_death_message(&(table->philos[i]));
			return (false);
		}
		if (philo_has_eaten_max_meals(&(table->philos[i])) == false)
			all_philos_has_eaten = false;
		i++;
	}
	if (all_philos_has_eaten == true)
		return (false);
	return (true);
}

t_checker *get_checker_function(t_table *table)
{
	if (table->options.max_meals == -1)
		return (&check_philo_status);
	else
		return (&check_philo_status_and_count_meals);
}

void *monitor(void *args)
{
	t_table *table;
	t_checker *checker;
	int i;

	table = (t_table *) args;
	checker = get_checker_function(table);
	i = 0;
	while (true)
	{
		if (checker(table) == false)
			break;
		usleep(100);
	}
	stop_sim(table);
	return (args);
}