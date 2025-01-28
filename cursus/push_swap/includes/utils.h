/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:39:33 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:19 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/**
 * This header file contains definitions of function that checks
 * and parse the args, then convers them to an array of interegers.
 */

# include "defs.h"

int		init_stacks(t_stack_group *stack, int ac, char **av);

int		already_in_stack(t_stack *s, int n);
int		notvalid_number(char *s);
int		all_args_are_valide_phase1(char *s);

int		stack_isempty(t_stack *stack);

void	clean_exit(void *p1, void *p2, void *p3, void *p4);

int		ft_isspace(int c);
int		ft_isnum(int c);
int		max(int a, int b);

int		ft_atoi_safe(t_stack *stack, char *s, int size);
int		convert_args_to_int(t_stack *a, char *s);

int		is_not_sorted(t_stack *stack);
int		stack_isempty(t_stack *stack);
int		get_element(t_stack *stack, int idx);

int		get_correct_count(int ac, char **av);
int		is_not_sorted(t_stack *stack);

void	free_stacks(t_stack_group stacks);

#endif
