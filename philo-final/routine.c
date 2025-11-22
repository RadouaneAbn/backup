/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:51:20 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 03:26:00 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	start_eating(t_philo *philo)
{
	print_message(philo, "has taken a fork");
	print_message(philo, "is eating");
	set_lastmeal(philo, get_current_time());
	ft_usleep(philo->options->time2eat);
	increment_meal_cout(philo);
}

void	eat(t_philo *philo, pthread_mutex_t *lf, pthread_mutex_t *rf)
{
	pthread_mutex_lock(lf);
	if (sim_is_running(philo) == true)
	{
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(rf);
		if (sim_is_running(philo) == true)
			start_eating(philo);
		pthread_mutex_unlock(rf);
	}
	pthread_mutex_unlock(lf);
}

void	start_routine(t_philo *philo)
{
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;

	shufle_forks(philo, &lf, &rf);
	set_lastmeal(philo, get_current_time());
	while (sim_is_running(philo) == true)
	{
		if (philo->id % 2)
			ft_usleep(1);
		print_message(philo, "is thinking");
		eat(philo, lf, rf);
		if (sim_is_running(philo) == true)
		{
			print_message(philo, "is sleeping");
			ft_usleep(philo->options->time2sleep);
		}
	}
}

void	run_one_philo(t_philo *philo)
{
	print_message(philo, "is thinking");
	set_lastmeal(philo, get_current_time());
	pthread_mutex_lock(philo->left_fork);
	print_message(philo, "has taken a fork");
	ft_usleep(philo->options->time2die);
	pthread_mutex_unlock(philo->left_fork);
}

void	*routine(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	if (philo->options->total_philos == 1)
		return (run_one_philo(philo), args);
	start_routine(philo);
	return (args);
}
