#include "tests.h"

#define UU "|     UP      |"
#define DD "|    DOWN     |"
#define LL "|    LEFT     |"
#define RR "|    RIGHT    |"
#define UL "|   UP_LEFT   |"
#define UR "|   UP_RIGHT  |"
#define DL "|  DOWN_LEFT  |"
#define DR "|  DOWN_RIGHT |"

void test_keys(t_game *game)
{
    write(1, "\r", 1);
    if (game->player.walk_direction.now == 0 && game->player.side_direction.now == 0)
        write(1, "|      0      |", 16);
    else if (game->player.walk_direction.now == -1 && game->player.side_direction.now == 1)
        write(1, UL, 16);
    else if (game->player.walk_direction.now == -1 && game->player.side_direction.now == -1)
        write(1, UR, 16);
    else if (game->player.walk_direction.now == 1 && game->player.side_direction.now == 1)
        write(1, DL, 16);
    else if (game->player.walk_direction.now == 1 && game->player.side_direction.now == -1)
        write(1, DR, 16);
    else if (game->player.walk_direction.now == -1)
        write(1, UU, 16);
    else if (game->player.walk_direction.now == 1)
        write(1, DD, 16);
    else if (game->player.side_direction.now == 1)
        write(1, LL, 16);
    else if (game->player.side_direction.now == -1)
        write(1, RR, 16);
}
