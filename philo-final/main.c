/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:36 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 03:27:06 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->options.total_philos)
	{
		if (pthread_create(&(table->philos[i].thread_id), NULL, routine,
				&(table->philos[i])) != 0)
		{
			perror("pthread_create (philo)");
			return (false);
		}
		i++;
	}
	if (pthread_create(&(table->monitor_pthread_id), NULL, monitor, table) != 0)
	{
		perror("pthread_create (monitor)");
		return (false);
	}
	return (true);
}

bool	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->options.total_philos)
	{
		if (pthread_join(table->philos[i].thread_id, NULL) != 0)
		{
			perror("pthread_join (philo)");
			return (false);
		}
		i++;
	}
	if (pthread_join(table->monitor_pthread_id, NULL) != 0)
	{
		perror("pthread_join (monitor)");
		return (false);
	}
	return (true);
}

bool	run_simulation(t_table *table)
{
	if (create_threads(table) == false)
		return (false);
	if (join_threads(table) == false)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_table	table;
	bool	status;

	if (ac > 6 || ac < 5)
	{
		printf(USAGE_ERROR_MSG, av[0]);
		return (1);
	}
	ft_bzero(&table, sizeof(t_table));
	status = convert_arguments(&table, ac, av);
	if (status == false)
		return (1);
	if (table.options.total_philos == 0 || table.options.max_meals == 0)
		return (0);
	if (status == true)
		status = init_simulation(&table);
	if (status == true)
		status = run_simulation(&table);
	if (status == false)
		return (1);
	return (0);
}
