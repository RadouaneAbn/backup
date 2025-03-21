#include "so_long.h"

void copy_xpm_to_window(t_game *game, int i, int j)
{
    mlx_put_image_to_window(game->data->mlx, game->data->window, game->map[i][j].tail, j * SIZE, i * SIZE);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

    // printf("%d, %d\n", x, y);
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void copy_xpm_pixels_to_window(t_data *data, t_pos pos, void *xpm, int frame)
{
	char *current_cell;
	int color;
	int x, y;
    t_data tmp;

	current_cell = mlx_get_data_addr(xpm, &tmp.bits_per_pixel, &tmp.line_length, &tmp.endian);
    current_cell += frame * 64 * (tmp.bits_per_pixel / 8);
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			color = *(unsigned int *)(current_cell + (y * tmp.line_length + x * (tmp.bits_per_pixel / 8)));
			if (color != FULLY_TR)
				my_mlx_pixel_put(data,  (pos.live_x - 32) + x, (pos.live_y - 32) + y, color);
			x++;
		}
		y++;
	}
}

void display_collectible(t_game *game, t_collectible *collectible, int frame)
{
    copy_xpm_pixels_to_window(game->data, collectible->pos, collectible->img.data, collectible->img.current_image);
    if (frame == COLL_FRAME)
        collectible->img.current_image = (collectible->img.current_image + 1) % collectible->img.images_count;
}

void load_floor_and_walls(t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            copy_xpm_pixels_to_window(game->data, game->map[i][j].pos, game->map[i][j].tail, 0);
            // copy_xpm_pixels_to_window(game->data, j * SIZE, i * SIZE, game->map[i][j].tail);
            j++;
        }
        i++;
    }
}

void load_collectibles(t_game *game)
{
    static int frame = 0;
    int i;
    t_collectible *collectible;

    i = 0;
    frame++;
    while (i < game->total_collectible)
    {
        collectible = &(game->entities.collectibles[i]);
        if (collectible->is_collected == FALSE)
            display_collectible(game, collectible, frame);
        i++;
    }
    if (frame == COLL_FRAME)
        frame = 0;
}

void animate_exit(t_game *game, t_exit *exit)
{
    static int frame = 0;
    static int inc = -1;

    copy_xpm_pixels_to_window(game->data, exit->pos, exit->img.data, exit->img.current_image);
    if (frame < 10)
        frame++;
    else
    {
        frame = 0;
        if (exit->img.current_image == 1 || exit->img.current_image == exit->img.images_count - 1)
            inc *= -1;
        exit->img.current_image = (exit->img.current_image + inc) % exit->img.images_count;
    }
}

void load_exit(t_game *game)
{
    if (game->entities.exit.is_open == FALSE)
        copy_xpm_pixels_to_window(game->data, game->entities.exit.pos, game->entities.exit.img.data, 0);
    else
        animate_exit(game, &(game->entities.exit));
}

void check_if_pos_reached(t_game *game, t_player *player, t_pos pos)
{
    static int directions[4][2] = {{-SEP, 0}, {SEP, 0}, {0, -SEP}, {0, SEP}};
    int (x), (y);

    if (player->state == IDLE)
        return ;
    if (player->facing->direction == LEFT && pos.live_x == pos.old_x - 64
        || player->facing->direction == RIGHT && pos.live_x == pos.old_x + 64
        || player->facing->direction == UP && pos.live_y == pos.old_y - 64
        || player->facing->direction == DOWN && pos.live_y == pos.old_y + 64)
    {
        (*total_moves())++;
        player->pos.old_x = player->pos.live_x;
        player->pos.old_y = player->pos.live_y;
    }
    x = ((pos.live_x) + directions[player->facing->direction][0]) / 64;
    y = ((pos.live_y) + directions[player->facing->direction][1]) / 64;
    if (game->map[y][x].type == '1')
        player->state = IDLE;
}

void update_player_pos(t_game *game, t_player *player)
{
    check_if_pos_reached(game, player, player->pos);
    if (player->state == IDLE)
        return ;
    if (player->facing->direction == LEFT)
        player->pos.live_x -= PLAYER_MOVE;
    else if (player->facing->direction == RIGHT)
        player->pos.live_x += PLAYER_MOVE;
    else if (player->facing->direction == UP)
        player->pos.live_y -= PLAYER_MOVE;
    else if (player->facing->direction == DOWN)
        player->pos.live_y += PLAYER_MOVE;
    player->pos.x = player->pos.live_x / 64;
    player->pos.y = player->pos.live_y / 64;
}

void animate_player(t_game *game, t_player *player, int frame[2])
{
    int idx;
    int player_facing;

    idx = player->state;
    if (player->facing)
        player_facing = player->facing->direction;
    else
        player_facing = player->last_direction;
    copy_xpm_pixels_to_window(game->data, game->entities.player.pos, game->entities.player.img.data[idx][player_facing], game->entities.player.img.current_image[idx]);
    if (frame[IDLE] == PLAYER_FRAME)
        player->img.current_image[idx] = (player->img.current_image[idx] + 1) % player->img.images_count[idx];
    if (frame[MOVING] == PLAYER_FRAME_MV)
        player->img.current_image[idx] = (player->img.current_image[idx] + 1) % player->img.images_count[idx];
    if (frame[idx] % 3  == 0)
        update_player_pos(game, player);
}

void load_player(t_game *game)
{
    static int frame[2] = {0, 0};
    int i;

    i = game->entities.player.state;
    frame[i]++;
    animate_player(game, &(game->entities.player), frame);
    if (frame[IDLE] == PLAYER_FRAME)
        frame[IDLE] = 0;
    if (frame[MOVING] == PLAYER_FRAME_MV)
        frame[MOVING] = 0;
}

// int search_for_clear_path(t_game *game, t_enemy *enemy, t_pos pos)
// {
//     static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     int i;

//     i = 0;
//     while (i < 4)
//     {
//         if (game->map[pos.x + directions[i][0]][pos.y + directions[i][1]].type != '1' )
//     }
    
// }

// void decide_enemy_next_move(t_game *game)
// {
//     static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
//     int i;
//     t_enemy *enemy;

//     i = -1;
//     while (++i < game->total_enemy)
//     {
//         enemy = &(game->entities.enemies[i]);
//         if (enemy->state == MOVING)
//             continue;
//         enemy->facing = search_for_clear_path(game, enemy, enemy->pos);
//     }
// }

int load_map(t_game *game)
{
    // decide_enemy_next_move(game);
    load_floor_and_walls(game);
    load_collectibles(game);
    load_exit(game);
    load_enemy(game);
    load_player(game);
    mlx_put_image_to_window(game->data->mlx, game->data->window, game->data->img, 0, 0);
    collusion_handle(game);
    return (0);
}