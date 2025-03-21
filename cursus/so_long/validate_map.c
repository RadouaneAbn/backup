#include "so_long.h"

int map_has_wall_boarders(t_game *game, char **map)
{
	int i;
	int j;

	i = game->map_height - 1;
	j = 0;
	while (j < game->map_width)
	{
		if (map[0][j] != '1' || map[i][j] != '1')
			return (FALSE);
		j++;
	}
	i = 0;
	j = game->map_width - 1;
	while (i < game->map_height)
	{
		if (map[i][0] != '1' || map[i][j] != '1')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int player_has_access_to_collectibles_exit(t_game *game, char **map)
{
    game->player_has_access_to_collectibles = 0;
    game->player_has_access_to_exit = 0;

    flood_fill_full(map, game->entities.player.pos.x, game->entities.player.pos.y, game);

    if (game->player_has_access_to_exit != 1
        || game->player_has_access_to_collectibles != game->total_collectible)
        return (FALSE);
    return (TRUE);
}

void validate_map(t_game *game, char **map)
{
    // if (game->map_width > (SCREEN_WIDTH / 64) || game->map_height > ((SCREEN_HEIGHT - 5) / 64))
    //     exit_error(1, BIG_MAP_ERR);
    if (game->total_collectible < 1 || game->total_player != 1 || game->total_exit != 1)
		map_components_invalide(game->total_player, game->total_exit, game->total_collectible);
    if (map_has_wall_boarders(game, map) == FALSE
        || player_has_access_to_collectibles_exit(game, map) == FALSE)
    {
        free_map_char(map);
        map_access_invalide(game);
    }
    free_map_char(map);
}