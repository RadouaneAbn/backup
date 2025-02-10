/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:27:00 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:27:01 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"
#include "../includes/operations.h"

t_move	*init_move(void)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	move->target = INT_MAX;
	move->target_idx = -1;
	move->targeted = 0;
	move->targeted_idx = 0;
	move->a_move = 0;
	move->b_move = 0;
	move->score = INT_MAX;
	return (move);
}

void	clear_move(t_move *move)
{
	move->target = INT_MAX;
	move->target_idx = -1;
	move->targeted = 0;
	move->targeted_idx = 0;
	move->a_move = 0;
	move->b_move = 0;
	move->score = INT_MAX;
}

void	copy_move_to(t_move *src, t_move *dst)
{
	dst->target = src->target;
	dst->target_idx = src->target_idx;
	dst->targeted = src->targeted;
	dst->targeted_idx = src->targeted_idx;
	dst->a_move = src->a_move;
	dst->b_move = src->b_move;
	dst->score = src->score;
}

void	make_move_separate(t_stack_group stack, int *move,
		void rv(t_stack_group, int), void rrv(t_stack_group, int))
{
	while (*move > 0)
	{
		rv(stack, 1);
		(*move)--;
	}
	while (*move < 0)
	{
		rrv(stack, 1);
		(*move)++;
	}
}

void	make_move(t_stack_group stack, t_move *move)
{
	if (move->a_move >= 0 && move->b_move >= 0)
	{
		while (move->a_move > 0 && move->b_move > 0)
		{
			rr(stack, 1);
			(move->a_move)--;
			(move->b_move)--;
		}
	}
	else if (move->a_move < 0 && move->b_move < 0)
	{
		while (move->a_move < 0 && move->b_move < 0)
		{
			rrr(stack, 1);
			(move->a_move)++;
			(move->b_move)++;
		}
	}
	make_move_separate(stack, &move->a_move, ra, rra);
	make_move_separate(stack, &move->b_move, rb, rrb);
}
