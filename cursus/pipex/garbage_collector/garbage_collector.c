// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
#include "../includes/garbage_collector.h"
#include "../includes/utils.h"

t_node	**collector(void)
{
	static t_node	*head = NULL;

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
	t_node	*node;

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
/*
int	main(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*s5;
	char	*s6;

	t_node **head, *cur;
	s1 = ft_malloc(20, 1);
	s2 = ft_malloc(20, 1);
	s3 = ft_malloc(20, 1);
	s4 = ft_malloc(20, 1);
	s5 = ft_malloc(20, 1);
	s6 = ft_malloc(20, 0);
 
	strcpy(s1, "hello s1");
	strcpy(s2, "hello s2");
	strcpy(s3, "hello s3");
	strcpy(s4, "hello s4");
	strcpy(s5, "hello s5");
	free_ptr(s1);
	free_ptr(s3);
	free_ptr(s5);
	head = collector();
	cur = *head;
	while (cur)
	{
		printf("%s\n", (char *)cur->data);
		cur = cur->next;
	}
	free_all();
	free(s6);
	return (0);
}
*/