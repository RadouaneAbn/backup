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
#include "../includes/utils.h"
<<<<<<< HEAD

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

int swappable(t_stack *s)
{
	if (get_element(s, 0) > get_element(s, 1))
		return (1);
	return (0);
}

int	sort_stack(t_stacks stack)
{
	t_move	*move;

	while ((stack.a->size > 3) && (stack.b->size < 2))
		pb(stack, 1);
	// short_sort_b(stack);
	while (stack.a->size > 0)
	{
		move = push_best_element(stack);
		make_move(stack, move);
		pb(stack, 1);
		free(move);
	}
	while (stack.b->size > 0)
		pa(stack, 1);
	organize_stack_a(stack);
	return (1);
}
=======
#include "../includes/push_swap.h"
>>>>>>> 218e8f4af2b25ed20c6f3afbe6fed82b29308091

int	main(int ac, char **av)
{
	t_stack_group	stacks;
	int				status;

	if (ac == 1)
		return (0);
	status = init_stacks(&stacks, ac, av);
	if (status == 0)
		return (status);
	if (is_not_sorted(stacks.a))
	{
		if (stacks.capacity <= 3)
			status = short_sort_a(stacks);
		else if (stacks.capacity <= 5)
			status = short_sort_6(stacks);
		else
			status = sort_stack(stacks);
	}
	free_stacks(stacks);
	if (status == -1)
		exit(1);
	return (0);
}
