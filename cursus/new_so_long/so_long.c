#include "so_long.h"

// void build_map(t_game *game, t_list **head)
// {
// 	char **map;

// }

t_game *build_game(char *map_path)
{
	int fd;
	t_list *head;
	t_game *game;

	head = NULL;
	fd = open_file(map_path);
	if (read_map(&head, fd) == -1)
	{
		close(fd);
		ft_lstclear(&head, free);
		exit_error(1, MALC_MGS);
	}
	close (fd);
	game = ft_smalloc(sizeof(t_game));
	if (game == NULL)
		exit_error(1, MALC_MGS);
	build_game_dimentions(game, &head);
	// build_map(game, &head);
	return (game);
}

int main(int ac, char **av)
{
    t_game *game;

    if (ac != 2)
        exit_error(1, USAGE_ERR);
    
    game = build_game(av[1]);
	(void) game;
	free_all();
	return (0);
}