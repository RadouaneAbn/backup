/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:40:37 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:40:39 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "defs.h"

void	pa(t_stack_group stack, int printable);
void	pb(t_stack_group stack, int printable);

void	sa(t_stack_group stack, int printable);
void	sb(t_stack_group stack, int printable);
void	ss(t_stack_group stack, int printable);

void	ra(t_stack_group stack, int printable);
void	rb(t_stack_group stack, int printable);
void	rr(t_stack_group stack, int printable);

void	rra(t_stack_group stack, int printable);
void	rrb(t_stack_group stack, int printable);
void	rrr(t_stack_group stack, int printable);

#endif
