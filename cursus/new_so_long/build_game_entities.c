#include "so_long.h"

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

void get_entities_count(t_game *game, char **map)
{
	int i;
	int j;

	i = 0;
	game->total_player = 0;
	game->total_enemy = 0;
	game->total_collectible = 0;
	game->total_exit = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if (map[i][j] == 'P')
			{
				game->entities.player.pos.x = j;
				game->entities.player.pos.y = i;
				game->total_player++;
			}
			else if (map[i][j] == 'N')
				game->total_enemy++;
			else if (map[i][j] == 'C')
				game->total_collectible++;
			else if (map[i][j] == 'E')
				game->total_exit++;
			j++;
		}
		i++;
	}
}

char **copy_map(t_list **head, int height, int width)
{
	char **map;
	int i;
	int j;
	t_list *current;
	char *tmp;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	if (map == NULL)
		exit_error(1, MALC_MGS);
	current = *head;
	while (current)
	{
		j = -1;
		tmp = ((char *)current->content);
		map[i] = malloc(sizeof(char) * width);
		if (map[i] == NULL)
			return (free_map_char(map), NULL);
		while (tmp[++j])
			map[i][j] = tmp[j];
		current = current->next;
		i++;
	}
	map[i] = NULL;
	return (map);
}

void build_game_dimentions(t_game *game, t_list **head)
{
	char **map;
	get_map_dimentions(game, head);
	map = copy_map(head, game->map_height, game->map_width);
	get_entities_count(game, map);
	validate_map(game, map);
}