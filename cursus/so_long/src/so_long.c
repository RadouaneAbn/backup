#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"
#include "../includes/garbage_collector.h"

void print_map(t_game *game)
{
	int i = 0, j;
	int c_idx;

	printf("MAP INFO:\n");
	printf("  dimentions: [%d/%d]\n", game->map_width, game->map_height);
	printf("  collectables: [%d]\n", game->collectibles);
	printf("  player: [%d/%d]\n\n", game->enteties.player.x, game->enteties.player.y);
	while (i < game->map_height) {
		j = 0;
		while (j < game->map_width) {
			printf("[%2d|%-2d] ", game->map[i][j].x, game->map[i][j].y);
			j++;
		}
		printf("\n");
		j = 0;
		while (j < game->map_width) {
			c_idx = 0;
			while (c_idx < game->collectibles)
			{
				// printf("[x: %d] [y: %d] [i: %d] [j: %d]\n", (game->enteties.collectables[c_idx]).x, (game->enteties.collectables[c_idx]).y, i, j);
				if (i == (game->enteties.collectables[c_idx]).y
					&& j == (game->enteties.collectables[c_idx]).x)
					{

						printf("[ COL ] ");
						break;
					}
				c_idx++;
			}
			if (c_idx < game->collectibles)
			{}
			else if (i == game->enteties.player.y && j == game->enteties.player.x)
				printf("[ PLY ] ");
			else if (game->map[i][j].type == WALL)
				printf("[ WAL ] ");
			else if (game->map[i][j].type == SPACE)
				printf("[ SPC ] ");
			else if (game->map[i][j].type == EXIT)
				printf("[ EXT ] ");
			j++;
		}
		printf("\n\n");
		i++;
	}
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

char *ft_remove_from_end(char *str, char del)
{
	int slen;
	int i;
	char *new_str;

	slen = ft_strlen(str);
	if (slen == 0)
		return (str);
	while (slen > 0 && str[slen - 1] == del)
		slen--;
	new_str = malloc(sizeof(char) * (slen + 1));
	if (new_str == NULL)
		exit_error(1, MALC_MGS);
	i = 0;
	while (i < slen)
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
		row = ft_remove_from_end(row, '\n');
		node = append_to_list(head, row);
		if (node == NULL)
			return (-1);
	}
	return (0);
}


t_cell_type get_map_cell_type(char c)
{
	if (c == 'C')
		return (SPACE);
	if (c == 'P')
		return (SPACE);
	if (c == 'E')
		return (EXIT);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (SPACE);
	return (INVALID);
}

t_cell_type get_cell_type(char c)
{
	if (c == 'C')
		return (COLLECTABLE);
	if (c == 'P')
		return (PLAYER);
	if (c == 'E')
		return (EXIT);
	if (c == '1')
		return (WALL);
	if (c == '0')
		return (SPACE);
	return (INVALID);
}

t_cell **copy_map(t_list **head)
{
	t_list *current;
	t_cell **map;
	int list_size;
	int i;
	int j;
	char *tmp_str;

	i = 0;
	list_size = ft_lstsize(*head);
	if (list_size == 0)
		exit_error(1, MAP_EMPTY);
	map = ft_smalloc(sizeof(t_cell *) * (list_size + 1));
	if (map == NULL)
		exit_error(1, MALC_MGS);
	current = *head;
	while (current)
	{
		j = 0;
		// (*head) = (*head)->next;
		tmp_str = (char *)(current->content);
		map[i] = ft_smalloc(sizeof(t_cell) * (ft_strlen(tmp_str)));
		while (tmp_str[j])
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].is_closed = FALSE;
			map[i][j].type = get_map_cell_type(tmp_str[j]);
			if (map[i][j].type == INVALID)
				return (NULL);
			j++;
		}
		// ft_lstdelone(current, free);
		current = current->next;
		i++;
	}
	return (map);
}

void map_components_invalide(int player, int map_exit, int collectibles)
{
	if (player != 1)
		write(2, PLAYER_ERR, ft_strlen(PLAYER_ERR));
	if (map_exit != 1)
		write(2, MAP_EXIT_ERR, ft_strlen(MAP_EXIT_ERR));
	if (collectibles < 1)
		write(2, COLLECTIBLES_ERR, ft_strlen(COLLECTIBLES_ERR));
	free_all();
	exit(1);
}

void copy_enteties(t_game *game, t_list **head)
{
	t_list *current;
	int i;
	int j;
	char *tmp_str;
	int exit_cell;
	int idx;

	i = 0;
	exit_cell = 0;
	current = *head;
	game->enteties.player.exist = 0;
	game->enteties.collectables = ft_smalloc(sizeof(t_collectable) * (game->collectibles));
	while (current)
	{
		j = 0;
		tmp_str = (char *)(current->content);
		while (tmp_str[j])
		{
			if (tmp_str[j] == 'C')
				game->collectibles++;
			else if (tmp_str[j] == 'P')
			{
				game->enteties.player.x = j;
				game->enteties.player.y = i;
				(game->enteties.player.exist)++;
			}
			else if (tmp_str[j] == 'E')
				exit_cell++;
			j++;
		}
		current = current->next;
		i++;
	}
	if ((game->enteties.player.exist) != 1 || exit_cell != 1 || game->collectibles < 1)
		map_components_invalide(game->enteties.player.exist, exit_cell, game->collectibles);
	game->enteties.collectables = ft_smalloc(sizeof(t_collectable) * (game->collectibles));
	i = 0;
	idx = 0;
	while (*head)
	{
		j = 0;
		current = *head;
		*head = (*head)->next;
		tmp_str = (char *)(current->content);
		while (tmp_str[j])
		{
			if (tmp_str[j] == 'C')
			{
				(game->enteties.collectables[idx]).is_collected = FALSE;
				(game->enteties.collectables[idx]).x = j;
				(game->enteties.collectables[idx]).y = i;
				idx++;
			}
			j++;
		}
		ft_lstdelone(current, free);
		i++;
	}
}

void get_map_dimentions(t_game *game, t_list **head)
{
	t_list *current;

	game->map_height = ft_lstsize(*head);
	game->map_width = ft_strlen((*head)->content);
	current = *head;
	while (current)
	{
		if ((int)ft_strlen(current->content) != game->map_width)
			exit_error(1, INVALID_MAP);
		current = current->next;
	}
}


// copy the map but as strings
char **copy_simple_map(t_list **head)
{

}

void build_game_dimentions(t_game *game, t_list **head)
{
	game->enteties.player.exist = 0;
	get_map_dimentions(game, head);
	game->map = copy_map(head);
	game->simple_map = copy_simple_map(head);
	game->collectibles = 0;
	game->exit_is_open = 0;
	copy_enteties(game, head);
	// game->enteties.collectables = ft_smalloc(sizeof(t_collectable) * (game->collectibles + 1));
}

// void breadth_first_full_search(t_game *game, char **map, int x, int y)
// {
// 	int i;
// 	int j;


// }

// void validate_map_flood_fill(t_game *game, char **map, int x, int y)
// {
// 	if (x > game->map_width || x < 0 || y > game->map_height || y < 0)
// 		return ;
// 	if (map[y][x] == '1')
// 		return ;
// 	if (map[y][x] == '0')
// 		map[y][x] = '1';
// 	if (map[y][x] == 'C')
// 	{
// 		game->player.collectibles++;
// 		map[y][x] = '1';
// 	}
// 	if (map[y][x] == 'E')
// 	{
// 		game->player.exit++;
// 		map[y][x] = '1';
// 	}
// 	validate_map_flood_fill(game, map, x + 1, y);
// 	validate_map_flood_fill(game, map, x, y + 1);
// 	validate_map_flood_fill(game, map, x - 1, y);
// 	validate_map_flood_fill(game, map, x, y - 1);
// }

void debug_flood_fill(t_game *game)
{
	printf("player pos: [%d,%d].\n", game->player.x, game->player.y);
	printf("player has access to %d c from %d c.\n", game->player.collectibles, game->collectibles);
	printf("player has access to exit == %d\n", game->player.exit);
}

void map_access_invalide(t_game *game)
{
	if (game->enteties.player.exit != 1)
		write(2, PLAYER_EXIT_ERR, ft_strlen(PLAYER_EXIT_ERR));
	if (game->enteties.player.collectibles != game->collectibles)
		write(2, PLAYER_COL_ERR, ft_strlen(PLAYER_COL_ERR));
	free_all();
	exit(1);
}

void validate_map(t_game *game)
{
	game->enteties.player.collectibles = 0;
	game->enteties.player.exit = 0;

	// printf("init ")
	// validate_map_flood_fill(game, map_copy, game->player.x, game->player.y);
	// breadth_first_full_search(game, map_copy, game->enteties.player.x, game->enteties.player.y);
	// debug_flood_fill(game);
	if (game->enteties.player.exit != 1 || game->enteties.player.collectibles != game->collectibles)
		map_access_invalide(game);
}

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
	print_map(game);
	validate_map(game);
	return (game);
}

int main(int ac, char **av)
{
	t_game *game;
	if (ac != 2)
	{
		write(2, "Usage: ./so_long MAP_PATH\n", 26);
		exit (1);
	}

	game = build_game(av[1]);
	(void) game;

	free_all();
	return (0);
}