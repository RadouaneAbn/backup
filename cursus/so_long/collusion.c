#include "so_long.h"

void check_collectible(t_game *game, t_collectible *collectible, t_player *player)
{
    if (collectible->is_collected)
        return ;
    if (ft_abs(player->pos.live_x - collectible->pos.live_x) < 20
        && ft_abs(player->pos.live_y - collectible->pos.live_y) < 32)
    {
        collectible->is_collected = TRUE;
        player->collected_collectibles++;
    }
}

void check_collectibles(t_game *game, t_player *player)
{
    int i;

    i = 0;
    while (i < game->total_collectible)
        check_collectible(game, &(game->entities.collectibles[i++]), player);
    if (player->collected_collectibles == game->total_collectible)
        game->entities.exit.is_open = TRUE;
}

void check_exit(t_game *game, t_player *player, t_exit *exit_door)
{
    int x_offset;
    int y_offset;

    y_offset = ft_abs(exit_door->pos.live_y - 16 - player->pos.live_y);
    x_offset = ft_abs(exit_door->pos.live_x - player->pos.live_x);
    if (x_offset < 26 && y_offset < 26)
    {
        ft_printf("\nYou Won !!!\n");
        close_mlx(game->data);
        exit(0);
    }
}

int collusion_handle(t_game *game)
{
    if (game->entities.exit.is_open == TRUE)
        check_exit(game, &(game->entities.player), &(game->entities.exit));
    if (game->entities.player.collected_collectibles != game->total_collectible)
        check_collectibles(game, &(game->entities.player));
    // check_enemy
    return (0);
}   