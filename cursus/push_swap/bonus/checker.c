/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:37:04 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:37:46 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	get_instruction(char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		return (PA);
	else if (ft_strcmp(s, "pb\n") == 0)
		return (PB);
	else if (ft_strcmp(s, "sa\n") == 0)
		return (SA);
	else if (ft_strcmp(s, "sb\n") == 0)
		return (SB);
	else if (ft_strcmp(s, "ss\n") == 0)
		return (SS);
	else if (ft_strcmp(s, "ra\n") == 0)
		return (RA);
	else if (ft_strcmp(s, "rb\n") == 0)
		return (RB);
	else if (ft_strcmp(s, "rr\n") == 0)
		return (RR);
	else if (ft_strcmp(s, "rra\n") == 0)
		return (RRA);
	else if (ft_strcmp(s, "rrb\n") == 0)
		return (RRB);
	else if (ft_strcmp(s, "rrr\n") == 0)
		return (RRR);
	else
		return (-1);
}

void	init_instructions(t_instruct (*instructions)[12])
{
	(*instructions)[PA] = pa;
	(*instructions)[PB] = pb;
	(*instructions)[SA] = sa;
	(*instructions)[SB] = sb;
	(*instructions)[SS] = ss;
	(*instructions)[RA] = ra;
	(*instructions)[RB] = rb;
	(*instructions)[RR] = rr;
	(*instructions)[RRA] = rra;
	(*instructions)[RRB] = rrb;
	(*instructions)[RRR] = rrr;
	(*instructions)[OP_COUNT] = NULL;
}

void	read_instructions(t_stacks stacks)
{
	char		*s;
	int			op_idx;
	t_instruct	instruction[12];

	init_instructions(&instruction);
	s = get_next_line(0);
	while (s != NULL)
	{
		op_idx = get_instruction(s);
		if (op_idx == -1)
			return ;
		instruction[op_idx](stacks, 0);
		s = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_stacks	stack;

	if (ac == 1)
		return (0);
	init_stack(&stack, ac, av);
	read_instructions(stack);
	if (is_not_sorted(stack.a) || stack_isempty(stack.b) == 0)
		write(1, "KO\n", 3);
	else
	{
		write(1, "OK\n", 3);
	}
	free_stacks(stack);
	return (0);
}
