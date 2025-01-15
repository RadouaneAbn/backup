/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_calls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:22 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:25:23 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"

void	rotate_stack(t_stack *stack)
{
	if (stack->size < 2)
		return ;
	stack->stack[stack->rear] = stack->stack[stack->front];
	stack->front = (stack->front + 1) % stack->capacity;
	stack->rear = (stack->rear + 1) % stack->capacity;
}

void	ra(t_stacks stack, int printable)
{
	if (printable)
		write(1, "ra\n", 3);
	rotate_stack(stack.a);
}

void	rb(t_stacks stack, int printable)
{
	if (printable)
		write(1, "rb\n", 3);
	rotate_stack(stack.b);
}

void	rr(t_stacks stack, int printable)
{
	if (printable)
		write(1, "rr\n", 3);
	rotate_stack(stack.a);
	rotate_stack(stack.b);
}
