/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:40:46 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:47 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*stack;
	int		size;
	int		front;
	int		rear;
	int		capacity;
}			t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
	int		capacity;
}			t_stacks;

typedef struct s_move
{
	int		target;
	int		target_idx;
	int		targeted;
	int		targeted_idx;
	int		a_move;
	int		b_move;
	int		score;
}			t_move;

#endif
