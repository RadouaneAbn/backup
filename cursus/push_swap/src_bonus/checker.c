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

int create_and_append_node(t_linkedlist *list, int n)
{
	t_list *node;

	node = (t_list *) malloc(sizeof(t_list));
	if (node == NULL)
		return (free_list(list->head), -1);
	node->n = n;
	node->next = NULL;
	if (list->head == NULL)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	return (0);
}

int	read_instructions(t_linkedlist *list)
{
	char		*s;
	int			op_idx;

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
	t_list *current;
	t_instruct	instruction[12];

	init_instructions(&instruction);
	current = list.head;
	while (current)
	{
		instruction[current->n](stack, 0);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	t_stacks	stack;
	t_linkedlist	list;
	int status;

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
