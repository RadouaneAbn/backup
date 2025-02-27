#include "../includes/so_long.h"
#include "../includes/get_next_line.h"
#include "../includes/utils.h"
#include "../libft/libft.h"
#include "../includes/garbage_collector.h"

void exit_error(int exit_status, char *msg)
{
	free_all();
	write(2, msg, ft_strlen(msg));
	// if (exit_error == INV_MAP_ST)
	// 	write(2, INV_MAP_MSG, ft_strlen(INV_MAP_MSG));
	// else if (exit_error == WRONG_EXT_ST)
	// 	write(2, WRONG_EXT_MSG, ft_strlen(WRONG_EXT_MSG));
	// else if (exit_error == OPEN_ERROR_ST)
	// 	write(2, OPEN_ERROR_MSG, ft_strlen(OPEN_ERROR_MSG));
	// else if (exit_error == MALC_ST)
	// 	write(2, MALC_MGS, ft_strlen(MALC_MGS));
	exit(exit_status);
}

int file_is_dot_ber(char *file_path)
{
	int file_path_len;

	file_path_len = ft_strlen(file_path);
	// printf("%s\n", file_path + (file_path_len - 4));
	if (ft_strncmp(file_path + (file_path_len - 4), ".ber", 5) == 0)
		return (1);
	return (0);
}

int open_file(char *map_path)
{
	int fd;

	if (file_is_dot_ber(map_path) == FALSE)
		exit_error(1, WRONG_EXT_MSG);
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		exit_error(1, OPEN_ERROR_MSG);
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
		// printf("=> %s", row);
		if (row == NULL)
			break;
		// save_ptr(row);
		row = ft_remove_from_end(row, '\n');
		node = append_to_list(head, row);
		if (node == NULL)
			return (-1);
	}
	return (0);
}

char **copy_map(t_list **head)
{
	t_list *current;
	char **map;
	int list_size;
	int i;

	i = 0;
	list_size = ft_lstsize(*head);
	if (list_size == 0)
		exit_error(1, MAP_EMPTY);
	map = ft_smalloc(sizeof(char *) * (list_size + 1));
	if (map == NULL)
		exit_error(1, MALC_MGS);
	while (*head)
	{
		current = *head;
		(*head) = (*head)->next;
		map[i] = ft_strdup((char *)(current->content));
		if (map[i] == NULL)
			exit_error(1, MALC_MGS);
		save_ptr(map[i]);
		ft_lstdelone(current, free);
		i++;
	}
	map[i] = NULL;
	return (map);
}

char **copy_map2(t_game *game)
{
	char **new_map;
	int i;

	new_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (new_map == NULL)
		exit_error(1, MALC_MGS);
	i = 0;
	while (game->map[i])
	{
		new_map[i] = ft_strdup(game->map[i]);
		if (new_map[i] == NULL)
		{
			while (--i >= 0)
				free(new_map[i]);
			exit_error(1, MALC_MGS);
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
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

void build_game_dimentions(t_game *game, t_list **head)
{
	int rows;
	int cols;
	int map_exit;

	game->player.exist = 0;
	map_exit = 0;
	game->map = copy_map(head);
	game->map_width = ft_strlen(game->map[0]);
	game->collectibles = 0;
	game->exit_is_open = 0;
	rows = 0;
	while (game->map[rows])
	{
		cols = 0;
		while (game->map[rows][cols])
		{
			if (game->map[rows][cols] == 'C')
				game->collectibles++;
			else if (game->map[rows][cols] == 'P')
			{
				game->player.x = cols;
				game->player.y = rows;
				(game->player.exist)++;
			}
			else if (game->map[rows][cols] == 'E')
			map_exit++;
			cols++;
		}
		if (cols != game->map_width)
		{
			printf("map width: %d || row width: %d", game->map_width, cols);
			exit_error(1, INVALID_MAP);
		}
		rows++;
	}
	if ((game->player.exist) != 1 || map_exit != 1 || game->collectibles < 1)
		map_components_invalide(game->player.exist, map_exit, game->collectibles);
	game->map_height = rows;
}

void validate_map_flood_fill(t_game *game, char **map, int x, int y)
{
	// printf("current pos [%d,%d]\n", x, y);
	if (x > game->map_width || x < 0 || y > game->map_height || y < 0)
		return ;
	if (map[y][x] == '1')
		return ;
	if (map[y][x] == '0')
		map[y][x] = '1';
	if (map[y][x] == 'C')
	{
		game->player.collectibles++;
		map[y][x] = '1';
	}
	if (map[y][x] == 'E')
	{
		game->player.exit++;
		map[y][x] = '1';
	}
	validate_map_flood_fill(game, map, x + 1, y);
	validate_map_flood_fill(game, map, x, y + 1);
	validate_map_flood_fill(game, map, x - 1, y);
	validate_map_flood_fill(game, map, x, y - 1);
}

void debug_flood_fill(t_game *game)
{
	printf("player pos: [%d,%d].\n", game->player.x, game->player.y);
	printf("player has access to %d c from %d c.\n", game->player.collectibles, game->collectibles);
	printf("player has access to exit == %d\n", game->player.exit);
}

void map_access_invalide(t_game *game)
{
	if (game->player.exit != 1)
		write(2, PLAYER_EXIT_ERR, ft_strlen(PLAYER_EXIT_ERR));
	if (game->player.collectibles != game->collectibles)
		write(2, PLAYER_COL_ERR, ft_strlen(PLAYER_COL_ERR));
	free_all();
	exit(1);
}

void validate_map(t_game *game)
{
	char **map_copy;
	int i;

	map_copy = copy_map2(game);
	game->player.collectibles = 0;
	game->player.exit = 0;
	validate_map_flood_fill(game, map_copy, game->player.x, game->player.y);
	// debug_flood_fill(game);
	i = 0;
	while (map_copy[i])
		free(map_copy[i++]);
	free(map_copy);
	if (game->player.exit != 1 || game->player.collectibles != game->collectibles)
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