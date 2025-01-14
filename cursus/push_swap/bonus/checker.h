/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:38:28 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:38:42 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../get_next_line/get_next_line.h"
# include "../operations.h"
# include "../utils.h"

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

#endif
