/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:24:51 by rabounou          #+#    #+#             */
/*   Updated: 2025/02/08 16:01:34 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"

int	stack_isempty(t_stack *stack)
{
	return (stack->size == 0);
}

int	get_element(t_stack *stack, int idx)
{
	if (idx < 0)
		return (stack->stack[(stack->rear + idx + stack->capacity)
				% stack->capacity]);
	return (stack->stack[(stack->front + idx) % stack->capacity]);
}
