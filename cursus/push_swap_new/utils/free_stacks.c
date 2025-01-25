/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:31:36 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/14 15:32:46 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/defs.h"

void	free_stacks(t_stacks stacks)
{
	free(stacks.a->stack);
	free(stacks.b->stack);
	free(stacks.a);
	free(stacks.b);
}
