#include "so_long.h"

void build_floor(t_game *game, int i, int j)
{
    game->map[i][j].type = '0';
    game->map[i][j].pos.x = j;
    game->map[i][j].pos.y = i;
    game->map[i][j].pos.live_x = j * SIZE + 32;
    game->map[i][j].pos.live_y = i * SIZE + 32;
}

void build_wall(t_game *game, int i, int j)
{
    game->map[i][j].tail = game->map[0][0].tail;
    game->map[i][j].type = '1';
    game->map[i][j].pos.x = j;
    game->map[i][j].pos.y = i;
    game->map[i][j].pos.live_x = j * SIZE + 32;
    game->map[i][j].pos.live_y = i * SIZE + 32;
}

void *get_enemy(t_game *game)
{
    static void *enemy;
    int width;
    int height;

    width = 256;
    height = 64;
    if (enemy == NULL)
        enemy = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_ID, &width, &height);
    return (enemy);
}

void *get_enemy_xpms(t_game *game, int state, int direction)
{
    static void *all_enemy_xpm[2][4] = {{NULL, NULL, NULL, NULL}, {NULL, NULL, NULL, NULL}};
    int (width), (height);

    if (all_enemy_xpm[0][0] != NULL)
        return all_enemy_xpm[state][direction];
    
    all_enemy_xpm[IDLE][LEFT] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_IL, &width, &height);
    all_enemy_xpm[IDLE][RIGHT] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_IR, &width, &height);
    all_enemy_xpm[IDLE][UP] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_IU, &width, &height);
    all_enemy_xpm[IDLE][DOWN] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_ID, &width, &height);
    all_enemy_xpm[MOVING][LEFT] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_ML, &width, &height);
    all_enemy_xpm[MOVING][RIGHT] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_MR, &width, &height);
    all_enemy_xpm[MOVING][UP] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_MU, &width, &height);
    all_enemy_xpm[MOVING][DOWN] = mlx_xpm_file_to_image(game->data->mlx, ENEMY_PATH_MD, &width, &height);
    return (all_enemy_xpm[state][direction]);
}

void get_enemy_data(t_game *game, t_xpm1 *xpm)
{
    xpm->data[IDLE][LEFT] = get_enemy_xpms(game, IDLE, LEFT);
    xpm->data[IDLE][RIGHT] = get_enemy_xpms(game, IDLE, RIGHT);
    xpm->data[IDLE][UP] = get_enemy_xpms(game, IDLE, UP);
    xpm->data[IDLE][DOWN] = get_enemy_xpms(game, IDLE, DOWN);
    xpm->data[MOVING][LEFT] = get_enemy_xpms(game, IDLE, LEFT);
    xpm->data[MOVING][RIGHT] = get_enemy_xpms(game, IDLE, RIGHT);
    xpm->data[MOVING][UP] = get_enemy_xpms(game, IDLE, UP);
    xpm->data[MOVING][DOWN] = get_enemy_xpms(game, IDLE, DOWN);
}

int get_random_moves()
{
    int moves;

    moves = rand() % 20;
    return (moves);
}

int get_clear_path(t_game *game, t_enemy *enemy)
{
    static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int rnd;
    int (i), (x), (y);

    i = 0;
    rnd = rand() % 4;
    while (i < 4)
    {
        x = enemy->pos.x + directions[rnd][0];
        y = enemy->pos.y + directions[rnd][1];
        if (game->map[y][x].type != '1')
            break;
        rnd = (rnd + 1) % 4;
        i++;
    }
    if (i == 4)
    {
        enemy->state = IDLE;
        return (DOWN);
    }
    return (rnd);
}

void build_enemy(t_game *game, int i, int j)
{
    int idx;

    idx = 0;
    while (idx < game->total_enemy
            && game->entities.enemies[idx].pos.x != -1)
        idx++;

    game->entities.enemies[idx].pos.x = j;
    game->entities.enemies[idx].pos.y = i;
    game->entities.enemies[idx].pos.live_x = (j * SIZE) + 32;
    game->entities.enemies[idx].pos.live_y = (i * SIZE) + 32;
    game->entities.enemies[idx].pos.old_x = (j * SIZE) + 32;
    game->entities.enemies[idx].pos.old_y = (i * SIZE) + 32;
    game->entities.enemies[idx].state = IDLE;
    game->entities.enemies[idx].facing = get_clear_path(game, &(game->entities.enemies[idx]));
    game->entities.enemies[idx].moves = get_random_moves();
    game->entities.enemies[idx].img.current_image[IDLE] = 0;
    game->entities.enemies[idx].img.current_image[MOVING] = 0;
    game->entities.enemies[idx].img.images_count[IDLE] = 4;
    game->entities.enemies[idx].img.images_count[MOVING] = 6;
    get_enemy_data(game, &(game->entities.enemies[idx].img));
}

void get_player_data(t_game *game, t_xpm1 *xpm, int width, int height)
{
    // NOTE: Still needs error handle `if image does not exist`
    xpm->data[IDLE][LEFT] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_IL, &width, &height);
    xpm->data[IDLE][RIGHT] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_IR, &width, &height);
    xpm->data[IDLE][UP] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_IU, &width, &height);
    xpm->data[IDLE][DOWN] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_ID, &width, &height);
    xpm->data[MOVING][LEFT] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_ML, &width, &height);
    xpm->data[MOVING][RIGHT] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_MR, &width, &height);
    xpm->data[MOVING][UP] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_MU, &width, &height);
    xpm->data[MOVING][DOWN] = mlx_xpm_file_to_image(game->data->mlx, PLAYER_PATH_MD, &width, &height);
}

void build_player(t_game *game, int i, int j)
{
    int size;

    size = SIZE;
    game->entities.player.pos.x = j;
    game->entities.player.pos.y = i;
    game->entities.player.pos.live_x = (j * SIZE) + 32;
    game->entities.player.pos.live_y = (i * SIZE) + 32;
    game->entities.player.pos.old_x = (j * SIZE) + 32;
    game->entities.player.pos.old_y = (i * SIZE) + 32;
    game->entities.player.state = IDLE;
    game->entities.player.last_direction = DOWN;
    game->entities.player.facing = NULL;
    game->entities.player.collected_collectibles = 0;
    game->entities.player.img.current_image[0] = 0;
    game->entities.player.img.current_image[1] = 0;
    game->entities.player.img.images_count[0] = 8;
    game->entities.player.img.images_count[1] = 8;
    get_player_data(game, &(game->entities.player.img), 512, 64);
}

void *get_collectible(t_game *game, int size)
{
    static void *col = NULL;
    int width;

    width = 320;
    if (col == NULL)
        col = mlx_xpm_file_to_image(game->data->mlx, COINS_PATH, &width, &size);
    return (col);
}

void *get_exit(t_game *game, int size)
{
    static void *exit = NULL;
    int width;

    width = 640;
    if (exit == NULL)
        exit = mlx_xpm_file_to_image(game->data->mlx, EXIT_PATH, &width, &size);
    return (exit);
}

void build_collectible(t_game *game, int i, int j)
{
    int idx;

    idx = 0;
    while (idx < game->total_collectible
            && game->entities.collectibles[idx].pos.x != -1)
        idx++;
    game->entities.collectibles[idx].pos.x = j;
    game->entities.collectibles[idx].pos.y = i;
    game->entities.collectibles[idx].pos.live_x = j * SIZE + 32;
    game->entities.collectibles[idx].pos.live_y = i * SIZE + 32;
    game->entities.collectibles[idx].is_collected = FALSE;
    game->entities.collectibles[idx].img.current_image = 0;
    game->entities.collectibles[idx].img.images_count = 5;
    game->entities.collectibles[idx].img.data = get_collectible(game, SIZE);
}

void build_exit(t_game *game, int i, int j)
{
    int idx;

    idx = 0;
    game->entities.exit.pos.x = j;
    game->entities.exit.pos.y = i;
    game->entities.exit.pos.live_x = j * SIZE + 32;
    game->entities.exit.pos.live_y = i * SIZE + 32;
    game->entities.exit.is_open = FALSE;
    game->entities.exit.img.current_image = 1;
    game->entities.exit.img.images_count = 10;
    game->entities.exit.img.data = get_exit(game, SIZE);
}
