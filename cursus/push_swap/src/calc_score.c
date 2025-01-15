/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_score.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:34:27 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:34:45 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"
#include "../includes/push_swap.h"
#include "../includes/utils.h"

void	calculate_score(t_stacks stack, t_move *move)
{
	int	a;
	int	b;
	int	score;

	a = move->targeted_idx;
	b = move->target_idx;
	if (move->a_move >= 0 && move->b_move >= 0)
		score = max(a, b);
	else if (move->a_move < 0 && move->b_move < 0)
		score = max(stack.a->size - a, stack.b->size - b);
	else if (move->a_move >= 0)
		score = a + (stack.b->size - b);
	else
		score = (stack.a->size - a) + b;
	move->score = score;
}

int	find_side(t_stack *s, int idx)
{
	int	middle;

	if (s->size % 2 == 0)
		middle = s->size / 2 - 1;
	else
		middle = s->size / 2;
	if (idx <= middle)
		return (idx);
	else
		return (-(s->size - idx));
}

int	find_target(t_stack *s, t_move *move)
{
	int	i;
	int	current;

	i = 0;
	while (i < s->size)
	{
		current = get_element(s, i);
		if (move->targeted > current && move->target < current)
		{
			move->target = current;
			move->target_idx = i;
		}
		i++;
	}
	if (move->target_idx != -1)
		return (move->target_idx);
	return (find_max(s, move));
}

void	find_best_move(t_stacks stack, t_stack *s, t_move *move)
{
	move->target_idx = find_target(s, move);
	move->a_move = find_side(stack.a, move->targeted_idx);
	move->b_move = find_side(stack.b, move->target_idx);
	calculate_score(stack, move);
}

t_move	*push_best_element(t_stacks stack)
{
	t_move	*move;
	t_move	*current;
	int		i;

	i = 0;
	current = init_move();
	move = init_move();
	while (i < stack.a->size)
	{
		clear_move(current);
		current->targeted = get_element(stack.a, i);
		current->targeted_idx = i;
		find_best_move(stack, stack.b, current);
		if (current->score < move->score)
			copy_move_to(current, move);
		if (move->score == 0)
			break ;
		i++;
	}
	free(current);
	return (move);
}
