/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:28 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 20:55:56 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "operations.h"
# include "utils.h"

typedef struct s_list {
	int n;
	struct s_list *next;
}	t_list;

typedef struct s_linkedlist {
	t_list *head;
	t_list *tail;
}	t_linkedlist;

enum			e_op
{
	PA,
	PB,
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
};

typedef void	(*t_instruct)(t_stacks, int);

int				ft_strcmp(const char *s1, const char *s2);
void	free_list(t_list *head);

#endif
