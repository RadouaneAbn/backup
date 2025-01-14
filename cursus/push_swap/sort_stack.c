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
 * short_sort: Sort a stack of size 3 or less
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
