/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:51:11 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 03:25:05 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

bool	philo_is_alive(t_philo *philo)
{
	bool	philo_status;

	pthread_mutex_lock(&(philo->last_meal_lock));
	philo_status = get_current_time()
		- philo->last_meal <= (size_t)(philo->options->time2die);
	pthread_mutex_unlock(&(philo->last_meal_lock));
	return (philo_status);
}

bool	philo_has_eaten_max_meals(t_philo *philo)
{
	bool	max_meals_status;

	pthread_mutex_lock(&(philo->max_meals_lock));
	max_meals_status = philo->meals_count >= philo->options->max_meals;
	pthread_mutex_unlock(&(philo->max_meals_lock));
	return (max_meals_status);
}

void	increment_meal_cout(t_philo *philo)
{
	pthread_mutex_lock(&(philo->max_meals_lock));
	philo->meals_count++;
	pthread_mutex_unlock(&(philo->max_meals_lock));
}

void	shufle_forks(t_philo *philo, pthread_mutex_t **lf, pthread_mutex_t **rf)
{
	if (philo->id % 2 == 1)
	{
		*lf = philo->left_fork;
		*rf = philo->right_fork;
	}
	else
	{
		*lf = philo->right_fork;
		*rf = philo->left_fork;
	}
}
