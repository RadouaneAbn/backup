#include "so_long.h"

void map_access_invalide(t_game *game)
{
    ft_putstr_fd(ERROR, 2);
	if (game->player_has_access_to_exit != 1)
		ft_putstr_fd(PLAYER_EXIT_ERR, 2);
	if (game->player_has_access_to_collectibles != game->total_collectible)
		ft_putstr_fd(PLAYER_COL_ERR, 2);
	free_all();
	exit(1);
}

void map_components_invalide(int player, int map_exit, int collectibles)
{
	ft_putstr_fd(ERROR, 2);
	if (player != 1)
		ft_putstr_fd(PLAYER_ERR, 2);
	if (map_exit != 1)
		ft_putstr_fd(MAP_EXIT_ERR, 2);
	if (collectibles < 1)
		ft_putstr_fd(COLLECTIBLES_ERR, 2);
	free_all();
	exit(1);
}

void exit_error(int exit_status, char *msg)
{
	free_all();
    ft_putstr_fd(ERROR, 2);
    if (msg == NULL)
        perror(NULL);
    else
	    ft_putstr_fd(msg, 2);
	exit(exit_status);
}