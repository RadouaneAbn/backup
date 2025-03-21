# include "so_long.h"

int ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

int get_random_moves()
{
    int moves;

    moves = srand() % 20;
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
