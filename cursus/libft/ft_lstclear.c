#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	current = *lst;
	while (current)
	{
		tmp = current;
		current = current->next;
		ft_lstdelone(current, del);
	}
	*lst = NULL;
}
