#include "so_long.h"

int *total_moves()
{
	static int a = 1;
	ft_printf("\rtotal moves: %d", a);

	return (&a);
}

void init_map_resources(t_game *game, char **map)
{
	int i;

	game->entities.collectibles = ft_smalloc(sizeof(t_collectible) * game->total_collectible);
	if (game->total_enemy > 0)
		game->entities.enemies = ft_smalloc(sizeof(t_enemy) * game->total_enemy);
	game->map = ft_smalloc(sizeof(t_cell *) * game->map_height);
	if (game->map == NULL)
		exit_error(1, MALC_MGS);
	i = 0;
	while (i < game->map_height)
	{
		game->map[i] = ft_smalloc(sizeof(t_cell) * game->map_width);
		if (game->map[i] == NULL)
			exit_error(1, MALC_MGS);
		i++;
	}
}

void border_tail(t_game *game, int i, int j)
{
	int size;

	size = SIZE;
	game->map[i][j].type = '1';
	game->map[i][j].pos.x = j;
	game->map[i][j].pos.y = i;
	game->map[i][j].pos.live_x = j * SIZE + 32;
	game->map[i][j].pos.live_y = i * SIZE + 32;
	game->map[i][j].tail = mlx_xpm_file_to_image(game->data->mlx, WALL_PATH, &size, &size);
}

void classify_entity(t_game *game, char **map, int i, int j)
{
	if (map[i][j] == 'P')
		build_player(game, i, j);
	else if (map[i][j] == 'C')
		build_collectible(game, i, j);
	else if (map[i][j] == 'N')
		build_enemy(game, i, j);
	else if (map[i][j] == 'E')
		build_exit(game, i, j);
	else if (map[i][j] == '1')
		build_wall(game, i, j);
}

int is_wall(t_game *game, char **map, int i, int j)
{
	if (i >= game->map_height || j >= game->map_width || i < 0 || j < 0)
		return (FALSE);
	if (map[i][j] == '1')
		return (TRUE);
	return (FALSE);
}

void classify_floor_helper(t_game *game, char **map, int i, int j)
{
	static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	int x;
	int y;
	int dir_idx;
	int floor_id;

	dir_idx = 0;
	floor_id = 0;
	while (dir_idx < 4)
	{
		x = j + directions[dir_idx][1];
		y = i + directions[dir_idx][0];
		if (is_wall(game, map, y, x) == TRUE)
			floor_id |= (1 << dir_idx);
		dir_idx++;
	}
	game->map[i][j].tail = get_xpm_using_mask(floor_id);
	game->map[i][j].pos.x = j;
    game->map[i][j].pos.y = i;
    game->map[i][j].pos.live_x = j * SIZE + 32;
    game->map[i][j].pos.live_y = i * SIZE + 32;
}

void classify_floor(t_game *game, char **map, int i, int j)
{
	if (map[i][j] != '0')
		classify_entity(game, map, i, j);
	classify_floor_helper(game, map, i, j);
}

void init_entities(t_game *game)
{
	int i;
	int size;

	size = SIZE;
	game->entities.enemies = ft_smalloc(sizeof(t_enemy) * game->total_enemy);
	if (game->entities.enemies == NULL)
		exit_error(1, MALC_MGS);
	game->entities.collectibles = ft_smalloc(sizeof(t_collectible) * game->total_collectible);
	if (game->entities.collectibles == NULL)
		exit_error(1, MALC_MGS);
	i = 0;
	while (i < game->total_enemy)
		game->entities.enemies[i++].pos.x = -1;
	i = 0;
	while (i < game->total_collectible)
		game->entities.collectibles[i++].pos.x = -1;
	game->map[0][0].tail = mlx_xpm_file_to_image(game->data->mlx, WALL_PATH, &size, &size);
}

void load_map_resources(t_game *game, char **map)
{
	int i;
	int j;

	i = 0;
	init_mask_array(game);
	init_entities(game);
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map[i][j] == '1')
				border_tail(game, i, j);
			else
				classify_floor(game, map, i, j);
			j++;
		}
		i++;
	}
}

void build_map(t_game *game, t_list **head)
{
	char **map;

	// TODO: free the linked list
	map = copy_map(head, game->map_height, game->map_width);
	init_mlx(game);
	init_map_resources(game, map);
	load_map_resources(game, map);
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
	build_map(game, &head);
	return (game);
}

void start_game(t_game *game)
{
	mlx_do_key_autorepeatoff(game->data->mlx);
	mlx_hook(game->data->window, 17, 0, close_mlx, game->data);
	mlx_hook(game->data->window, 2, 1L << 0, handle_key_press, game);
	mlx_loop_hook(game->data->mlx, load_map, (void *)game);
	mlx_hook(game->data->window, 3, 1L << 1, handle_keys_release, game);
    mlx_loop(game->data->mlx);
}

int main(int ac, char **av)
{
    t_game *game;

    if (ac != 2)
        exit_error(1, USAGE_ERR);
    
    game = build_game(av[1]);
	(void) game;
	game->game_status = 0;
	start_game(game);
	free_all();
	return (0);
}