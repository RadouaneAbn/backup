#include "so_long.h"

static t_list *append_to_list(t_list **head, char *row)
{
	t_list *node;

	node = ft_lstnew(row);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(head, node);
	return (node);
}

static char *ft_strip(char *str, char del)
{
	int slen;
	int i;
	char *new_str;

	slen = ft_strlen(str);
	if (slen == 0)
		return (str);
    if (str[slen - 1] != del)
        return (str);
	new_str = malloc(sizeof(char) * (slen));
	if (new_str == NULL)
		exit_error(1, MALC_MGS);
	i = 0;
	while (i < slen - 1)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	free(str);
	return (new_str);
}

int read_map(t_list **head, int fd)
{
	char *row;
	t_list *node;
	*head = NULL;

	while (TRUE)
	{
		row = get_next_line(fd);
		if (row == NULL)
			break;
		row = ft_strip(row, '\n');
		node = append_to_list(head, row);
		if (node == NULL)
			return (-1);
	}
	return (0);
}