#include "so_long.h"

// void flood_fill(char map[10][10], int x, int y, t_game *game)
void flood_fill_full(char **map, int x, int y, t_game *game)
{
    if (x >= game->map_width || y >= game->map_height || map[y][x] == '1'
        || x < 0 || y < 0)
        return ;

    if (map[y][x] == 'C')
        game->player_has_access_to_collectibles++;
    else if (map[y][x] == 'E')
        game->player_has_access_to_exit++;
    map[y][x] = '1';
    
    flood_fill_full(map, x + 1, y, game);
    flood_fill_full(map, x - 1, y, game);
    flood_fill_full(map, x, y + 1, game);
    flood_fill_full(map, x, y - 1, game);
}

// int main() {
//     t_game game;
//     char map[10][10] = {
//         {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
//         {'1', 'C', '0', '0', '0', '0', '0', 'C', 'P', '1'},
//         {'1', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
//         {'1', '0', '1', '0', '0', 'N', '0', '0', '0', '1'},
//         {'1', '0', '1', '0', '0', '0', '0', '0', '0', '1'},
//         {'1', '0', '1', 'N', '1', 'C', '0', '0', '0', '1'},
//         {'1', '0', '1', '0', '1', '0', '0', 'C', '0', '1'},
//         {'1', '0', '1', '0', '1', '0', '1', '1', '1', '1'},
//         {'1', 'P', '1', '0', '1', 'E', '1', 'E', '1', '1'},
//         {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
//     };
//     game.map_width = 10;
//     game.map_height = 10;
//     game.total_collectible = 0;
//     game.total_enemy = 0;
//     game.total_exit = 0;
//     game.total_player = 0;

//     flood_fill(map, 1, 8, &game);
//     for (int i = 0; i < 10; i++) {
//         for (int j = 0; j < 10; j++) {
//             printf("%c", map[i][j]);
//         }
//         printf("\n");
//     }

//     printf("\nTotal Player: %d\n", game.total_player);
//     printf("Total Collectible: %d\n", game.total_collectible);
//     printf("Total Exit: %d\n", game.total_exit);
//     printf("Total Enemy: %d\n", game.total_enemy);
// }