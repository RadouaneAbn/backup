/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:13:57 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:15:08 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	find_max(t_stack *s, t_move *move)
{
	int	i;
	int	current;
	int	max;
	int	max_idx;

	i = 0;
	max = INT_MIN;
	while (i < s->size)
	{
		current = get_element(s, i);
		if (current > max)
		{
			max = current;
			max_idx = i;
		}
		i++;
	}
	move->target = max;
	move->target_idx = max_idx;
	return (max_idx);
}

int	find_min_idx(t_stack *s)
{
	int	i;
	int	current;
	int	min;
	int	min_idx;

	i = 0;
	min = INT_MAX;
	while (i < s->size)
	{
		current = get_element(s, i);
		if (current < min)
		{
			min = current;
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

int	find_min(t_stack *s, t_move *move)
{
	int	min_idx;

	min_idx = find_min_idx(s);
	move->target_idx = min_idx;
	move->target = get_element(s, min_idx);
	return (min_idx);
}
