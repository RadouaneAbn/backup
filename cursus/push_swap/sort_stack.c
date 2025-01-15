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

#include "operations.h"
#include "utils.h"

/**
 * short_sort_a: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int	short_sort_a(t_stacks s)
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

/**
 * short_sort_5: Sort a stack of size 3 or less
 * Note:
 *  The sorting is done by making sure that the highest
 *  number is in the buttom of the stack
 *  then swith the first two elements if needed
 */

int	short_sort_6(t_stacks s)
{ 
	while (s.a->size != 3)
		pb(s, 1);

	short_sort_a(s);
	while (s.b->size != 0)
	{
		if (get_element(s.a, 0) > get_element(s.a, 1)
				&& get_element(s.b, 0) < get_element(s.b, 1))
			ss(s, 1);
		else if (get_element(s.a, 0) > get_element(s.a, 1))
			sa(s, 1);
		else if (get_element(s.b, 0) < get_element(s.b, 1))
			sb(s, 1);
		if (get_element(s.b, 0) < get_element(s.a, 0))
			pa(s, 1);
		
	}
	return (1);
}

/*
void sort_5_nodes(t_stack **stack_a, t_stack **stack_b)
{
    int min_index;

    while (stack_size(*stack_a) > 3)
    {
        min_index = get_min_index(*stack_a);
        if (min_index <= stack_size(*stack_a) / 2)
        {
            while (min_index-- > 0)
                ra(stack_a);
        }
        else
        {
            min_index = stack_size(*stack_a) - min_index;
            while (min_index-- > 0)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_3_nodes(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}

void sort_4_nodes(t_stack **stack_a,t_stack **stack_b)
{
    int min_index;

    while (stack_size(*stack_a) > 3)
    {
        min_index = get_min_index(*stack_a);
        if (min_index <= stack_size(*stack_a) / 2)
        {
            while (min_index-- > 0)
                ra(stack_a);
        }
        else
        {
            min_index = stack_size(*stack_a) - min_index;
            while (min_index-- > 0)
                rra(stack_a);
        }
        pb(stack_a, stack_b);
    }
    sort_3_nodes(stack_a);
    pa(stack_a, stack_b);
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a);
}
*/
