#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

static t_list	**collector(void)
{
	static t_list	*head;

	head = NULL;
	return (&head);
}

void	free_all(void)
{
	t_list	**head;
	t_list	*cur;
	t_list	*next;

	head = collector();
	cur = *head;
	while (cur)
	{
		next = cur->next;
		free(cur->content);
		free(cur);
		cur = next;
	}
	*head = NULL;
}

void	free_ptr(void *addr)
{
	t_list	**head;
	t_list	*current;
	t_list	*prev;
	t_list	*tmp;

	head = collector();
	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	prev = NULL;
	while (current)
	{
		tmp = current;
		if (current->content == addr)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(tmp->content);
			free(tmp);
			break ;
		}
		prev = tmp;
		current = current->next;
	}
}

t_list	*create_node(void *data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = data;
	node->next = NULL;
	return (node);
}

t_list	*add_front(t_list **head, void *data)
{
	t_list	*node;

	node = create_node(data);
	if (node == NULL)
		return (NULL);
	node->next = *head;
	*head = node;
	return (node);
}

void	save_ptr(void *data)
{
	t_list	**head;

	head = collector();
	add_front(head, data);
}

void	*ft_smalloc(int size)
{
	void	*mal;

	mal = malloc(size);
	if (mal == NULL)
		clean_exit(1);
	save_ptr(mal);
	return (mal);
}

void	*ft_malloc(int size)
{
	void	*mal;

	mal = malloc(size);
	if (mal == NULL)
		clean_exit(1);
	return (mal);
}
