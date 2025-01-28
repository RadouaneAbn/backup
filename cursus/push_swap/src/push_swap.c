/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:25:55 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 13:07:52 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/operations.h"
#include "../includes/utils.h"
#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack_group	stacks;
	int				status;

	if (ac == 1)
		return (0);
	status = init_stacks(&stacks, ac, av);
	if (status == 0)
		return (status);
	if (is_not_sorted(stacks.a))
	{
		if (stacks.capacity <= 3)
			status = short_sort_a(stacks);
		else if (stacks.capacity <= 6)
			status = short_sort_6(stacks);
		else
			status = sort_stack(stacks);
	}
	free_stacks(stacks);
	if (status == -1)
		exit(1);
	return (0);
}
