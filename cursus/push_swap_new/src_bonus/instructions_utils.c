/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 14:22:42 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/16 14:22:44 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

int	read_instructions(t_linkedlist *list)
{
	char	*s;
	int		op_idx;

	s = get_next_line(0);
	while (s != NULL)
	{
		op_idx = get_instruction(s);
		free(s);
		if (op_idx == -1)
			return (-1);
		if (create_and_append_node(list, op_idx) == -1)
			return (-1);
		s = get_next_line(0);
	}
	return (0);
}

void	execute_instructions(t_stacks stack, t_linkedlist list)
{
	t_list		*current;
	t_instruct	instruction[12];
	void (*func[12])(t_stack, int);

	init_instructions(&instruction);
	current = list.head;
	while (current)
	{
		instruction[current->n](stack, 0);
		current = current->next;
	}
}
