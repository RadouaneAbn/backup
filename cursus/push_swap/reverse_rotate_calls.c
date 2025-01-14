/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_calls.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:41 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:25:42 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

void	reverse_rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->front = (stack->front - 1 + stack->capacity) % stack->capacity;
	stack->rear = (stack->rear - 1 + stack->capacity) % stack->capacity;
	stack->stack[stack->front] = stack->stack[stack->rear];
}

void	rra(t_stacks stack, int printable)
{
	if (printable)
		printf("rra\n");
	reverse_rotate_stack(stack.a);
}

void	rrb(t_stacks stack, int printable)
{
	if (printable)
		printf("rrb\n");
	reverse_rotate_stack(stack.b);
}

void	rrr(t_stacks stack, int printable)
{
	if (printable)
		printf("rrr\n");
	reverse_rotate_stack(stack.a);
	reverse_rotate_stack(stack.b);
}
