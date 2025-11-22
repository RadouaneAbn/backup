/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 02:50:22 by rabounou          #+#    #+#             */
/*   Updated: 2025/07/28 02:53:42 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static bool	validate_args(t_table *table, int ac)
{
	if (table->options.total_philos < 0 || table->options.total_philos > 200)
		return (false);
	if (table->options.time2die <= 0)
		return (false);
	if (table->options.time2eat <= 0)
		return (false);
	if (table->options.time2sleep <= 0)
		return (false);
	if (ac == 6 && table->options.max_meals < 0)
		return (false);
	return (true);
}

bool	convert_arguments(t_table *table, int ac, char **av)
{
	if (ft_atoi(av[1], &(table->options.total_philos)) == false)
		return (false);
	table->options.total_forks = table->options.total_philos;
	if (ft_atoi(av[2], &(table->options.time2die)) == false)
		return (false);
	if (ft_atoi(av[3], &(table->options.time2eat)) == false)
		return (false);
	if (ft_atoi(av[4], &(table->options.time2sleep)) == false)
		return (false);
	if (ac == 6)
	{
		if (ft_atoi(av[5], &(table->options.max_meals)) == false)
			return (false);
	}
	else
		table->options.max_meals = -1;
	if (validate_args(table, ac) == false)
		return (false);
	return (true);
}
