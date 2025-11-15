#include "cube.h"

int	handle_keys_release(int keycode, t_game *game)
{
	if (keycode == UP_BUTTON)			// UP
	{
		if (game->player.walk_direction.now == -1)
			game->player.walk_direction.now = game->player.walk_direction.before;
		game->player.walk_direction.before = 0;
	}
	else if (keycode == DOWN_BUTTON)    // DOWN
	{
		if (game->player.walk_direction.now == 1)
			game->player.walk_direction.now = game->player.walk_direction.before;
		game->player.walk_direction.before = 0;
	}
	else if (keycode == RIGHT_BUTTON)    // RIGHT
	{
		if (game->player.side_direction.now == -1)
			game->player.side_direction.now = game->player.side_direction.before;
		game->player.side_direction.before = 0;
	}
	else if (keycode == LEFT_BUTTON)     // LEFT
	{
		if (game->player.side_direction.now == 1)
			game->player.side_direction.now = game->player.side_direction.before;
		game->player.side_direction.before = 0;
	}
	else if (keycode == RIGHT_ARROW)	// rotate right
	{
		if (game->player.rotation_direction.now == 1)
			game->player.rotation_direction.now = game->player.rotation_direction.before;
		game->player.rotation_direction.before = 0;
	}
	else if (keycode == LEFT_ARROW)	// rotate left
	{
		if (game->player.rotation_direction.now == -1)
			game->player.rotation_direction.now = game->player.rotation_direction.before;
		game->player.rotation_direction.before = 0;
	}
	return (0);
}

int	handle_key_press(int keycode, t_game *game)
{
	t_player *player = &game->player;

	if (keycode == UP_BUTTON)			// UP
	{
		player->walk_direction.before = player->walk_direction.now;
		player->walk_direction.now = -1;
	}
	else if (keycode == DOWN_BUTTON)    // DOWN
	{
		player->walk_direction.before = player->walk_direction.now;
		player->walk_direction.now = 1;
	}
	else if (keycode == RIGHT_BUTTON)    // RIGHT
	{
		player->side_direction.before = player->side_direction.now;
		player->side_direction.now = -1;
	}
	else if (keycode == LEFT_BUTTON)     // LEFT
	{
		player->side_direction.before = player->side_direction.now;
		player->side_direction.now = 1;
	}
	else if (keycode == RIGHT_ARROW)	// rotate right
	{
		player->rotation_direction.before = player->rotation_direction.before;
		player->rotation_direction.now = 1;
	}
	else if (keycode == LEFT_ARROW)	// rotate left
	{
		player->rotation_direction.before = player->rotation_direction.before;
		player->rotation_direction.now = -1;
	}
	else if (keycode == ESCAPE)
		exit_game(game);
	return (0);
}
