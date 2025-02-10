/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:00:11 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/08 16:00:27 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

void	organize_stack_a(t_stack_group stack)
{
	int	idx;
	int	moves_count;

	idx = find_min_idx(stack.a);
	moves_count = find_side(stack.a, idx);
	if (moves_count >= 0)
	{
		while (moves_count > 0)
		{
			ra(stack, 1);
			moves_count--;
		}
	}
	else
	{
		while (moves_count < 0)
		{
			rra(stack, 1);
			moves_count++;
		}
	}
}

int	*copy_array(t_stack *stack, int size)
{
	int	*array;
	int	i;

	array = malloc(sizeof(int) * size);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i] = get_element(stack, i);
		i++;
	}
	return (array);
}

int	push_to_b_according_to_median(t_stack_group stacks)
{
	int	*array;
	int	median;

	array = copy_array(stacks.a, stacks.capacity);
	if (array == NULL)
		return (-1);
	insertion_sort(array, stacks.capacity);
	median = array[stacks.capacity / 2];
	while (stacks.a->size != 0)
	{
		if (get_element(stacks.a, 0) > median)
		{
			pb(stacks, 1);
			rb(stacks, 1);
		}
		else
			pb(stacks, 1);
	}
	free(array);
	return (0);
}
