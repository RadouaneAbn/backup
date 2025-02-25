#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"
#include "../includes/garbage_collector.h"

void exit_error(int exit_status, int exit_error)
{
	free_all();
	if (exit_error == INV_MAP_ST)
		write(2, INV_MAP_MSG, ft_strlen(INV_MAP_MSG));
	if (exit_error == WRONG_EXT_ST)
		write(2, WRONG_EXT_MSG, ft_strlen(WRONG_EXT_MSG));
	if (exit_error == OPEN_ERROR_ST)
		write(2, OPEN_ERROR_MSG, ft_strlen(OPEN_ERROR_MSG));
	exit(exit_status);
}

int open_file(char *map_path)
{
	int fd;

	if (map_is_ber_file(map_path) == FALSE)
		exit_error(1, WRONG_EXT_ST);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error(1, OPEN_ERROR_ST);
	return (fd);
}

t_list *append_to_list(t_list **head, char *row)
{
	t_list *node;

	node = ft_lstnew(row);
	if (node == NULL)
		return (NULL);
	ft_lstadd_back(head, node);
	return (node);
}

int read_map(t_list **head, int fd)
{
	char *row;
	t_list *node;
	*head = NULL;

	row = get_next_line(fd);
	while (row != NULL)
	{
		node = append_to_list(&head, row);
		if (node == NULL)
			return (-1);
		row = get_next_line(fd);
	}
	return (0);
}

char **build_map(char *map_path)
{
	int fd;
	t_list *head;
	int status;

	fd = open_file(map_path);
	if (read_map(&head, fd) == -1)
		exit_error()
}

int main(int ac, char **av)
{
	char **map;
	if (ac != 2)
	{
		write(2, "Usage: ./so_long MAP_PATH\n", 26);
		exit (1);
	}

	map = build_map(av[1]);
}