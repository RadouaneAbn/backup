#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

t_node	**collector(void)
{
	static t_node	*head;

	head = NULL;
	return (&head);
}

void	free_all(void)
{
	t_node	**head;
	t_node	*cur;
	t_node	*next;

	head = collector();
	cur = *head;
	while (cur)
	{
		next = cur->next;
		free(cur->data);
		free(cur);
		cur = next;
	}
	*head = NULL;
}

void	free_ptr(void *addr)
{
	t_node	**head;
	t_node	*current;
	t_node	*prev;
	t_node	*tmp;

	head = collector();
	if (head == NULL || *head == NULL)
		return ;
	current = *head;
	prev = NULL;
	while (current)
	{
		tmp = current;
		if (current->data == addr)
		{
			if (prev != NULL)
				prev->next = current->next;
			else
				*head = current->next;
			free(tmp->data);
			free(tmp);
			break ;
		}
		prev = tmp;
		current = current->next;
	}
}

t_node	*create_node(void *data)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_node	*add_front(t_node **head, void *data)
{
	t_node	*node;

	node = create_node(data);
	if (node == NULL)
		return (NULL);
	node->next = *head;
	*head = node;
	return (node);
}

void	save_ptr(void *data)
{
	t_node	**head;

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
