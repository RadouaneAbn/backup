/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:18 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 02:51:26 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	sim_is_running(t_philo *philo)
{
	bool	sim_status;

	pthread_mutex_lock(&(philo->options->sim_lock));
	sim_status = philo->options->sim_running;
	pthread_mutex_unlock(&(philo->options->sim_lock));
	return (sim_status);
}

void	start_sim(t_table *table)
{
	pthread_mutex_lock(&(table->options.sim_lock));
	table->options.sim_running = true;
	pthread_mutex_unlock(&(table->options.sim_lock));
}

void	stop_sim(t_table *table)
{
	pthread_mutex_lock(&(table->options.sim_lock));
	table->options.sim_running = false;
	pthread_mutex_unlock(&(table->options.sim_lock));
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	set_lastmeal(t_philo *philo, size_t time)
{
	pthread_mutex_lock(&(philo->last_meal_lock));
	philo->last_meal = time;
	pthread_mutex_unlock(&(philo->last_meal_lock));
}
