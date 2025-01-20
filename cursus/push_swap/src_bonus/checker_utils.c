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

int	create_and_append_node(t_linkedlist *list, int n)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node == NULL)
		return (free_list(list->head), -1);
	node->n = n;
	node->next = NULL;
	if (list->head == NULL)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
	return (0);
}

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
