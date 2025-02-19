/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:09 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/08 16:00:56 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

/**
 * short_sort_a: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int	short_sort_a(t_stack_group s)
{
	if (s.a->size > 2 && get_element(s.a, 0) > get_element(s.a, 1) && get_element(s.a,
			0) > get_element(s.a, 2))
		ra(s, 1);
	else if (s.a->size > 2 && get_element(s.a, 1) > get_element(s.a, 0) && get_element(s.a,
			1) > get_element(s.a, 2))
		rra(s, 1);
	if (s.a->size > 1 && get_element(s.a, 0) > get_element(s.a, 1))
		sa(s, 1);
	return (1);
}

int	short_sort_b(t_stack_group s)
{
	if (s.b->size > 2 && get_element(s.b, 0) < get_element(s.b, 1) && get_element(s.b,
			0) < get_element(s.b, 2))
		rb(s, 1);
	else if (s.b->size > 2 && get_element(s.b, 1) < get_element(s.b, 0) && get_element(s.b,
			1) < get_element(s.b, 2))
		rrb(s, 1);
	if (s.b->size > 1 && get_element(s.b, 0) < get_element(s.b, 1))
		sb(s, 1);
	return (1);
}

int	short_sort_6(t_stack_group s)
{
	int	min_idx;
	int	side;

	while (s.a->size > 3)
	{
		min_idx = find_min_idx(s.a);
		side = find_side(s.a, min_idx);
		make_move_separate(s, &side, ra, rra);
		pb(s, 1);
	}
	short_sort_a(s);
	short_sort_b(s);
	while (s.b->size != 0)
		pa(s, 1);
	return (1);
}

int	sort_stack(t_stack_group stacks)
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
