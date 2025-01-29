/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:09 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:25:10 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"
#include "../debug/debug.h"

/**
 * short_sort_a: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int	short_sort_a(t_stack_group s)
{
	if (get_element(s.a, 0) > get_element(s.a, 1) && get_element(s.a,
			0) > get_element(s.a, 2))
		ra(s, 1);
	else if (get_element(s.a, 1) > get_element(s.a, 0) && get_element(s.a,
			1) > get_element(s.a, 2))
		rra(s, 1);
	if (get_element(s.a, 0) > get_element(s.a, 1))
		sa(s, 1);
	return (1);
}

int	short_sort_b(t_stack_group s)
{
	if (get_element(s.b, 0) < get_element(s.b, 1) && get_element(s.b,
			0) < get_element(s.b, 2))
		rb(s, 1);
	else if (get_element(s.b, 1) < get_element(s.b, 0) && get_element(s.b,
			1) < get_element(s.b, 2))
		rrb(s, 1);
	if (get_element(s.b, 0) < get_element(s.b, 1))
		sb(s, 1);
	return (1);
}

int get_idx(t_stack *s, int value)
{
	int i;

	i = 0;
	while (i < s->size)
	{
		if (value == get_element(s, i))
			return (i);
		i++;
	}
	return (-1);
}

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void copy_and_sort_array(t_stack_group stacks, int arr[5])
{
	int i;

	i = -1;
	while (++i < stacks.a->size)
		arr[i] = get_element(stacks.a, i);
	insertion_sort(arr, stacks.a->size);
}

void short_sort_5_healper(t_stack_group s, int elm1, int elm2)
{
	int a;
	int b;
	int last;

	a = find_side(s.a, get_idx(s.a, elm1));
	b = find_side(s.a, get_idx(s.a, elm2));
	last = 1;
	if (ft_abs(a) < ft_abs(b))
		make_move_separate(s, &a, ra, rra);
	else
		make_move_separate(s, &b, ra, rra);
}

int	short_sort_5(t_stack_group s)
{
	int arr[5];
	int a;
	int b;
	int c;

	copy_and_sort_array(s, arr);
	a = find_side(s.a, get_idx(s.a, arr[0]));
	b = find_side(s.a, get_idx(s.a, arr[1]));
	if (ft_abs(a) < ft_abs(b))
	{
		c = 1;
		make_move_separate(s, &a, ra, rra);
	}
	else
	{
		c = 0;
		make_move_separate(s, &b, ra, rra);
	}
	pb(s, 1);
	b = find_side(s.a, get_idx(s.a, arr[c]));
	make_move_separate(s, &b, ra, rra);
	pb(s, 1);

	if (get_element(s.a, 0) > get_element(s.a, 1) && get_element(s.a,
			0) > get_element(s.a, 2))
	{
		if (get_element(s.b, 0) < get_element(s.b, 1))
			rr(s, 1);
		else
			ra(s, 1);
	}
	else if (get_element(s.a, 1) > get_element(s.a, 0) && get_element(s.a,
			1) > get_element(s.a, 2))
	{
		if (get_element(s.b, 0) < get_element(s.b, 1))
			rrr(s, 1);
		else
			rra(s, 1);
	}
	if (get_element(s.a, 0) > get_element(s.a, 1))
	{
		if (get_element(s.b, 0) < get_element(s.b, 1))
			ss(s, 1);
		else
			sa(s, 1);
	}
	if (get_element(s.b, 0) < get_element(s.b, 1))
		sb(s, 1);
	while (s.b->size != 0)
		pa(s, 1);
	return (0);
}

// int	short_sort_5(t_stack_group s)
// {
// 	int	min_idx;
// 	int	side;

// 	while (s.a->size > 3)
// 	{
// 		min_idx = find_min_idx(s.a);
// 		side = find_side(s.a, min_idx);
// 		make_move_separate(s, &side, ra, rra);
// 		pb(s, 1);
// 	}
// 	short_sort_a(s);
// 	short_sort_b(s);
// 	while (s.b->size != 0)
// 		pa(s, 1);
// 	return (1);
// }

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