/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:30 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 02:50:58 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < time)
		usleep(100);
}

void	ft_usleep_safe(t_philo *philo, size_t time)
{
	size_t	start;

	start = get_current_time();
	while (get_current_time() - start < time && sim_is_running(philo))
		usleep(100);
}
