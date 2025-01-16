/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:37:04 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 20:57:34 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	main(int ac, char **av)
{
	t_stacks		stack;
	t_linkedlist	list;
	int				status;

	if (ac == 1)
		return (0);
	init_stack(&stack, ac, av);
	list.head = NULL;
	list.tail = NULL;
	status = read_instructions(&list);
	if (status == -1)
		clean_exit(stack.a->stack, stack.b->stack, stack.a, stack.b);
	execute_instructions(stack, list);
	if (is_not_sorted(stack.a) || stack_isempty(stack.b) == 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stacks(stack);
	free_list(list.head);
	return (0);
}
