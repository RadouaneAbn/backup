#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"
#include "../includes/garbage_collector.h"
#include "../includes/queue.h"

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
	write(2, "Error\n^^^^^\\ ", 13);
	if (player != 1)
		write(2, PLAYER_ERR, ft_strlen(PLAYER_ERR));
	if (map_exit != 1)
		write(2, MAP_EXIT_ERR, ft_strlen(MAP_EXIT_ERR));
	if (collectibles < 1)
		write(2, COLLECTIBLES_ERR, ft_strlen(COLLECTIBLES_ERR));
	free_all();
	exit(1);
}

t_game *copy_enteties(t_game *game, t_list **head)
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
	// game->enteties.collectables = ft_smalloc(sizeof(t_collectable) * (game->collectibles));
	// if (game->enteties.collectables == NULL)
	// 	return (NULL);
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
	current = *head;
	while (current)
	{
		j = 0;
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
		// ft_lstdelone(current, free);
		current = current->next;
		i++;
	}
	return (game);
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

void free_simple_map(t_map_mask **simple_map)
{
	int i;

	i = 0;
	while (simple_map[i])
		free(simple_map[i++]);
	free(simple_map);
}

t_map_mask **copy_simple_map(t_list **head, int height, int width)
{
	t_map_mask **map;
	int i;
	int j;
	t_list *current;
	char *tmp;

	i = 0;
	map = malloc(sizeof(t_map_mask *) * (height + 1));
	if (map == NULL)
		exit_error(1, MALC_MGS);
	current = *head;
	while (current)
	{
		j = -1;
		tmp = ((char *)current->content);
		map[i] = malloc(sizeof(t_map_mask) * width);
		if (map[i] == NULL)
			return (free_simple_map(map), NULL);
		while (tmp[++j])
		{
			map[i][j].c = tmp[j];
			map[i][j].is_visited = FALSE;
		}
		current = current->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void build_game_dimentions(t_game *game, t_list **head)
{
	game->enteties.player.exist = 0;
	get_map_dimentions(game, head);
	game->map = copy_map(head);
	game->collectibles = 0;
	game->exit_is_open = 0;
	// copy_simple_map(head, game->map_height);
	copy_enteties(game, head);
	// game->enteties.collectables = ft_smalloc(sizeof(t_collectable) * (game->collectibles + 1));
}

void map_access_invalide(t_game *game)
{
	write(2, "Error\n^^^^^\\ ", 13);
	if (game->enteties.player.exit != 1)
		write(2, PLAYER_EXIT_ERR, ft_strlen(PLAYER_EXIT_ERR));
	if (game->enteties.player.collectibles != game->collectibles)
		write(2, PLAYER_COL_ERR, ft_strlen(PLAYER_COL_ERR));
	free_all();
	exit(1);
}

int map_has_wall_boarders(t_map_mask **map, t_game *game)
{
	int i;
	int j;

	i = game->map_height - 1;
	j = 0;
	while (j < game->map_width)
	{
		if (map[0][j].c != '1' || map[i][j].c != '1')
			return (FALSE);
		j++;
	}
	i = 0;
	j = game->map_width - 1;
	while (i < game->map_height)
	{
		if (map[i][0].c != '1' || map[i][j].c != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_pos *copy_pos(int x, int y)
{
	t_pos *pos;

	pos = malloc(sizeof(t_pos));
	if (pos == NULL)
		return (NULL);
	pos->x = x;
	pos->y = y;
	return (pos);
}

void debug_bfs(t_map_mask **map, t_pos *pos, t_game *game)
{
	int i;
	int j;

		(void) pos;
	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
				printf("%c", map[i][j].c);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void check_and_append_neighbors(t_queue *queue, t_pos *pos, t_game *game, t_map_mask **map)
{
	if (pos->x + 1 < game->map_width && map[pos->y][pos->x + 1].c != '1'
		&& map[pos->y][pos->x + 1].is_visited == FALSE)
	{
		add_to_queue(queue, copy_pos(pos->x + 1, pos->y));
		map[pos->y][pos->x + 1].is_visited = TRUE;
	}
	if (pos->x - 1 >= 0 && map[pos->y][pos->x - 1].c != '1'
		&& map[pos->y][pos->x - 1].is_visited == FALSE)
	{
		add_to_queue(queue, copy_pos(pos->x - 1, pos->y));
		map[pos->y][pos->x - 1].is_visited = TRUE;
	}
	if (pos->y + 1 < game->map_height && map[pos->y + 1][pos->x].c != '1'
		&& map[pos->y + 1][pos->x].is_visited == FALSE)
	{
		add_to_queue(queue, copy_pos(pos->x, pos->y + 1));
		map[pos->y + 1][pos->x].is_visited = TRUE;
	}
	if (pos->y - 1 >= 0 && map[pos->y - 1][pos->x].c != '1'
		&& map[pos->y - 1][pos->x].is_visited == FALSE)
	{
		add_to_queue(queue, copy_pos(pos->x, pos->y - 1));
		map[pos->y - 1][pos->x].is_visited = TRUE;
	}
}


// tring to find a way to check if the current position is already visited 
// meaning it is already in the queue
void check_using_breadth_first_search(t_map_mask **map, t_game *game)
{
	t_queue *queue;
	t_pos *pos;

	queue = create_queue();
	pos = copy_pos(game->enteties.player.x, game->enteties.player.y);
	map[pos->y][pos->x].is_visited = TRUE;
	add_to_queue(queue, pos);
	while (queue->is_empty == FALSE)
	{
		pos = pop_from_queue(queue);
		if (map[pos->y][pos->x].c == 'C')
		(game->enteties.player.collectibles)++;
		else if (map[pos->y][pos->x].c == 'E')
		(game->enteties.player.exit)++;
		check_and_append_neighbors(queue, pos, game, map);
		map[pos->y][pos->x].c = '.';
		free(pos);
	}
	free(queue);
}

int player_has_access_to_collectibles_exit(t_map_mask **map, t_game *game)
{
	game->enteties.player.collectibles = 0;
	game->enteties.player.exit = 0;
	
	check_using_breadth_first_search(map, game);

	if (game->enteties.player.exit != 1 || game->enteties.player.collectibles != game->collectibles)
		return (FALSE);
	return (TRUE);
}

void validate_map(t_game *game, t_list **head)
{
	t_map_mask **tmp_map;

	tmp_map = copy_simple_map(head, game->map_height, game->map_width);
	ft_lstclear(head, free);
	// int i = 0;
	// while (tmp_map[i])
	// 	printf("%s\n", tmp_map[i++]);
	// printf("init ")
	// validate_map_flood_fill(game, map_copy, game->player.x, game->player.y);
	// breadth_first_full_search(game, map_copy, game->enteties.player.x, game->enteties.player.y);
	// debug_flood_fill(game);
	// if (game->enteties.player.exit != 1 || game->enteties.player.collectibles != game->collectibles)
	// 	map_access_invalide(game);
	if (map_has_wall_boarders(tmp_map, game) == FALSE
		|| player_has_access_to_collectibles_exit(tmp_map, game) == FALSE)
	{
		free_simple_map(tmp_map);
		map_access_invalide(game);
		// exit_error(1, INV_MAP_MSG);
	}
	// if (player_has_access_to_(game, tmp_map) )
	free_simple_map(tmp_map);
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
	validate_map(game, &head);
	return (game);
}

int main(int ac, char **av){
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