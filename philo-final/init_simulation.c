/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:34 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 02:54:07 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	init_philo(t_table *table, int i)
{
	t_philo	*philo;

	philo = &(table->philos[i]);
	if (pthread_mutex_init(&(philo->last_meal_lock), NULL) != 0)
	{
		perror("pthread_mutex_init");
		return (false);
	}
	if (pthread_mutex_init(&(philo->max_meals_lock), NULL) != 0)
	{
		perror("pthread_mutex_init");
		pthread_mutex_destroy(&(philo->last_meal_lock));
		return (false);
	}
	philo->meals_count = 0;
	philo->last_meal = get_current_time();
	philo->options = &(table->options);
	philo->id = i + 1;
	philo->left_fork = &(table->forks[i]);
	philo->right_fork = &(table->forks[(i + 1) % table->options.total_forks]);
	return (true);
}

bool	serve_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->options.total_philos)
	{
		if (init_philo(table, i) == false)
			break ;
		i++;
	}
	if (i < table->options.total_philos)
	{
		while (--i >= 0)
		{
			pthread_mutex_destroy(&(table->philos[i].last_meal_lock));
			pthread_mutex_destroy(&(table->philos[i].max_meals_lock));
		}
		return (false);
	}
	return (true);
}

void	destroy_forks_mutexs(t_table *table, int last)
{
	int	i;

	i = 0;
	if (last == -1)
		destroy_forks_mutexs(table, table->options.total_forks);
	else
	{
		while (i < last)
		{
			if (pthread_mutex_destroy(&(table->forks[i])) != 0)
				perror("pthread_mutex_destroy (fork)");
			i++;
		}
	}
}

bool	create_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->options.total_forks)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			destroy_forks_mutexs(table, i);
			perror("pthread_mutex_init");
			return (false);
		}
		i++;
	}
	return (true);
}

int	init_simulation(t_table *table)
{
	table->options.sim_running = true;
	if (create_forks(table) == false)
		return (false);
	serve_forks(table);
	table->options.start_time = get_current_time();
	return (true);
}
