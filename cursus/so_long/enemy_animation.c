#include "so_long.h"


void check_if_enemy_pos_reached(t_game *game, t_enemy *enemy, t_pos pos)
{
    static int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int (x), (y);

    if (enemy->state == IDLE)
        return ;
    if ((pos.live_x - pos.old_x == 0) || (pos.live_y - pos.old_y == 3))
    {
        enemy->moves--;
        enemy->pos.old_x = enemy->pos.live_x;
        enemy->pos.old_y = enemy->pos.live_y;
    }
    x = ((pos.x) + directions[enemy->facing][0]);
    y = ((pos.y) + directions[enemy->facing][1]);
    if (game->map[y][x].type == '1' || enemy->moves <= 0)
    {
        enemy->facing = get_clear_path(game, enemy);
        enemy->moves = get_random_moves();
        enemy->state = IDLE;
    }
}

void update_enemy_pos(t_game *game, t_enemy *enemy)
{
    check_if_pos_reached(game, enemy, enemy->pos);
    if (enemy->state == IDLE)
        return ;
    if (enemy->facing == LEFT)
        enemy->pos.live_x -= ENEMY_MOVE;
    else if (enemy->facing == RIGHT)
        enemy->pos.live_x += ENEMY_MOVE;
    else if (enemy->facing == UP)
        enemy->pos.live_y -= ENEMY_MOVE;
    else if (enemy->facing == DOWN)
        enemy->pos.live_y += ENEMY_MOVE;
    enemy->pos.x = enemy->pos.live_x / 64;
    enemy->pos.y = enemy->pos.live_y / 64;
}

void animate_enemy(t_game *game, t_enemy *enemy, int frame)
{
    int idx;

    idx = enemy->state;
    copy_xpm_pixels_to_window(game->data, enemy->pos, enemy->img.data[idx][enemy->facing], enemy->img.current_image[idx]);
    if (frame == ENEMY_FRAME)
        enemy->img.current_image[idx] = (enemy->img.current_image[idx] + 1) % enemy->img.images_count[idx];
    // if (frame % 5 == 0)
        update_enemy_pos(game, enemy);
}

void load_enemy(t_game *game)
{
    static int frame = 0;
    int i;

    i = 0;
    frame++;
    while (i < game->total_enemy)
    {
        animate_enemy(game, &(game->entities.enemies[i]), frame);
        i++;
    }
    if (frame == ENEMY_FRAME)
        frame = 0;
}