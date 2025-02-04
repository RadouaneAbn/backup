#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum e_types {
	INT,
	CHAR,
	STRING,
	GARBAGE_COLLECTOR
}	DataType;

typedef struct s_list
{
	void						*data;
	DataType					type;
	struct s_list	*next;
}	t_list;

t_list **collector()
{
	static t_list *head = NULL;

	return (&head);
}

void free_all()
{
	t_list **head;
	t_list *cur;
	t_list *next;

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

void free_ptr(void *addr)
{
	t_list **head;
	t_list *current;
	t_list *prev;
	t_list *tmp;

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
			break;
		}
		prev = tmp;
		current = current->next;
	}
}

t_list *create_node(void *data)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

t_list *add_front(t_list **head, void *data)
{
	t_list *node;

	node = create_node(data);
	if (node == NULL)
		return (NULL);
	node->next = *head;
	*head = node;
	return (node);
}

void	save_ptr(void *data)
{
	t_list **head;
	t_list *node;

	head = collector();
	add_front(head, data);
}

void	*ft_malloc(int size, int save)
{
	void *mal;

	mal = malloc(size);
	if (mal == NULL)
		return (NULL);
	if (save)
		save_ptr(mal);
	return (mal);
}

int	main()
{
	t_list **head, *cur;
	char *s1 = ft_malloc(20, 1);
	char *s2 = ft_malloc(20, 1);
	char *s3 = ft_malloc(20, 1);
	char *s4 = ft_malloc(20, 1);
	char *s5 = ft_malloc(20, 1);
	char *s6 = ft_malloc(20, 0);
 
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