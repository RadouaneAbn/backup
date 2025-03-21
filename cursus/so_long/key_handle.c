#include "so_long.h"

int *key_id()
{
    static int i = FALSE;

    return (&i);
}

int handle_keys_release(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		pop_key(game, &(game->entities.player.facing), UP);
	else if (keycode == 115 || keycode == 65364)
		pop_key(game, &(game->entities.player.facing), DOWN);
	else if (keycode == 100 || keycode == 65363)
		pop_key(game, &(game->entities.player.facing), RIGHT);
	else if (keycode == 97 || keycode == 65361)
		pop_key(game, &(game->entities.player.facing), LEFT);
	return (0);
}

int handle_key_press(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		append_key(game, &(game->entities.player.facing), UP);
	else if (keycode == 115 || keycode == 65364)
		append_key(game, &(game->entities.player.facing), DOWN);
	else if (keycode == 100 || keycode == 65363)
		append_key(game, &(game->entities.player.facing), RIGHT);
	else if (keycode == 97 || keycode == 65361)
		append_key(game, &(game->entities.player.facing), LEFT);
    else if (keycode == 65307)
        close_mlx(game->data);
	return (0);
}
