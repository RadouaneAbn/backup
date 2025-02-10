#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"

int open_file(char *map_path)
{
    int fd;

    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Invalid Map\n", 12);
        exit(1);
    }
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
    if (status == -1)
    {
        write(2, "malloc error\n", 13);
        
    }
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