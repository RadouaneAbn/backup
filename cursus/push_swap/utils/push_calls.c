/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_calls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:26:48 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:45:16 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"

void	pa(t_stack_group stack, int printable)
{
	if (printable)
		write(1, "pa\n", 3);
	if (stack.b->size == 0)
		return ;
	stack.a->front = (stack.a->front - 1 + stack.capacity) % stack.capacity;
	stack.a->stack[stack.a->front] = stack.b->stack[stack.b->front];
	(stack.a->size)++;
	(stack.b->size)--;
	stack.b->front = (stack.b->front + 1) % stack.capacity;
}

void	pb(t_stack_group stack, int printable)
{
	if (printable)
		write(1, "pb\n", 3);
	if (stack.a->size == 0)
		return ;
	stack.b->front = (stack.b->front - 1 + stack.capacity) % stack.capacity;
	stack.b->stack[stack.b->front] = stack.a->stack[stack.a->front];
	(stack.b->size)++;
	(stack.a->size)--;
	stack.a->front = (stack.a->front + 1) % stack.capacity;
}
