/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:40:30 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:31 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "defs.h"

# define TOP_SIDE 1
# define BOTTOM_SIDE 2

int		sort_stack(t_stack_group stacks);
void	insertion_sort(int *arr, int size);
int		short_sort_a(t_stack_group s);
int		short_sort_6(t_stack_group s);

t_move	*init_move(void);
void	clear_move(t_move *move);
void	copy_move_to(t_move *src, t_move *dst);

int		find_max(t_stack *s, t_move *move);
int		find_min(t_stack *s, t_move *move);
int		find_min_idx(t_stack *s);
int		find_side(t_stack *s, int idx);

t_move	*push_best_element(t_stack_group stack);
int		push_to_b_according_to_median(t_stack_group stacks);
void	make_move(t_stack_group stack, t_move *move);

int		get_correct_count(int ac, char **av);
int		get_arg_count(char *s);

void	make_move_separate(t_stack_group stack, int *move,
			void rv(t_stack_group, int), void rrv(t_stack_group, int));

void	organize_stack_a(t_stack_group stack);
int		*copy_array(t_stack *stack, int size);

void	clean_exit(void *p1, void *p2, void *p3, void *p4);

#endif
