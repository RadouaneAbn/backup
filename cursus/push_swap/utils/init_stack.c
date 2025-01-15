/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:27:07 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:31:28 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	allocate_stack(t_stacks *stack, int args_count)
{
	stack->a = (t_stack *)malloc(sizeof(t_stack));
	if (stack->a == NULL)
		return (clean_exit(NULL, NULL, NULL, NULL), -1);
	stack->a->stack = malloc(sizeof(int) * (args_count));
	if (stack->a->stack == NULL)
		return (clean_exit(stack->a, NULL, NULL, NULL), -1);
	stack->b = (t_stack *)malloc(sizeof(t_stack));
	if (stack->b == NULL)
		return (clean_exit(stack->a->stack, stack->a, NULL, NULL), -1);
	stack->b->stack = malloc(sizeof(int) * (args_count));
	if (stack->b->stack == NULL)
		return (clean_exit(stack->b, stack->a->stack, stack->a, NULL), -1);
	return (0);
}

void	set_stack(t_stacks *stacks, int elements_count)
{
	stacks->capacity = elements_count;
	stacks->a->capacity = elements_count;
	stacks->a->size = 0;
	stacks->a->front = 0;
	stacks->b->capacity = elements_count;
	stacks->b->size = 0;
	stacks->b->front = 0;
}

int	init_stack(t_stacks *stack, int ac, char **av)
{
	int	i;
	int	elements_count;
	int	status;

	i = 1;
	elements_count = get_correct_count(ac, av);
	if (elements_count == 0)
		return (0);
	if (elements_count == -1)
		return (clean_exit(NULL, NULL, NULL, NULL), -1);
	status = allocate_stack(stack, elements_count);
	if (status == -1)
		return (-1);
	set_stack(stack, elements_count);
	while (i < ac)
	{
		if (convert_args_to_int(stack->a, av[i]) == -1)
			return (clean_exit(stack->b->stack, stack->a->stack, stack->b,
					stack->a), -1);
		i++;
	}
	stack->a->rear = stack->a->size % stack->a->capacity;
	stack->b->rear = stack->b->size % stack->b->capacity;
	return (1);
}
