/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:55 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 13:07:52 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

void	organize_stack_a(t_stacks stack)
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

int	push_to_b_according_to_median(t_stacks stacks)
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

int	sort_stack(t_stacks stacks)
{
	t_move	*move;

	if (push_to_b_according_to_median(stacks) == -1)
		return (-1);
	while (stacks.a->size != 2)
		pa(stacks, 1);
	while (stacks.b->size != 0)
	{
		move = push_best_element(stacks);
		if (move == NULL)
			return (-1);
		make_move(stacks, move);
		pa(stacks, 1);
		free(move);
	}
	organize_stack_a(stacks);
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	stacks;
	int			status;

	if (ac == 1)
		return (0);
	status = init_stacks(&stacks, ac, av);
	if (status == 0)
		return (status);
	if (is_not_sorted(stacks.a))
	{
		if (stacks.capacity <= 3)
			status = short_sort_a(stacks);
		else if (stacks.capacity <= 6)
			status = short_sort_6(stacks);
		else
			status = sort_stack(stacks);
	}
	free_stacks(stacks);
	if (status == -1)
		exit(1);
	return (0);
}
