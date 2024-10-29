#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*body;
	t_list	*current;
	t_list	*new_node;
	void	*tmp;

	head = NULL;
	body = NULL;
	current = lst;
	while (current)
	{
		tmp = f(current->content);
		if (del != NULL)
			del(current->content);
		new_node = ft_lstnew(tmp);
		if (head == NULL)
			head = new_node;
		if (body == NULL)
			body = new_node;
		else
		{
			body->next = new_node;
			body = body->next;
		}
		current = current->next;
	}
	return (head);
}
