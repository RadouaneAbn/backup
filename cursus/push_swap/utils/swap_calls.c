/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_calls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:23:58 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:24:42 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"

void	swap_elements(t_stack *stack)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->stack[stack->front];
	stack->stack[stack->front] = stack->stack[(stack->front + 1)
		% stack->capacity];
	stack->stack[(stack->front + 1) % stack->capacity] = tmp;
}

void	sa(t_stack_group stack, int printable)
{
	if (printable)
		write(1, "sa\n", 3);
	swap_elements(stack.a);
}

void	sb(t_stack_group stack, int printable)
{
	if (printable)
		write(1, "sb\n", 3);
	swap_elements(stack.b);
}

void	ss(t_stack_group stack, int printable)
{
	if (printable)
		write(1, "ss\n", 3);
	swap_elements(stack.a);
	swap_elements(stack.b);
}
