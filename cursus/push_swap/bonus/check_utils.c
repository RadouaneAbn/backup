/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabounou <rabounou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:52:58 by rabounou          #+#    #+#             */
/*   Updated: 2025/01/15 20:55:35 by rabounou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	free_list(t_list *head)
{
	t_list	*current;

	while (head)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
