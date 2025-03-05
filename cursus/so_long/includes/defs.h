#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define FALSE 0
#define TRUE 1


# define INV_MAP_ST 111
# define READ_ERROR_ST 112
# define OPEN_ERROR_ST 113
# define WRONG_EXT_ST 114
# define MALC_ST 115
# define MALC_MGS "Malloc Error\n"
# define WRONG_EXT_MSG "Wrong file extention [file.ber]\n"
# define INV_MAP_MSG "Invalid Map\n"
# define READ_ERROR_MSG "Cannot read file\n"
# define OPEN_ERROR_MSG "Cannot open file\n"
# define MAP_EMPTY "Map is empty\n"
# define INVALID_MAP "Invalid map !!!\n"
# define PLAYER_ERR "The map should contain one player !!!\n"
# define MAP_EXIT_ERR "The map should contain one exit !!!\n"
# define COLLECTIBLES_ERR "The map should contain at least one collectible !!!\n"
# define PLAYER_COL_ERR "The player doesn't have access to all collectibles !!!\n"
# define PLAYER_EXIT_ERR "The player doesn't have access the exit !!!\n"
# define REGULAR_FILE_ERR "Invalid map file !!!\n"
# define FILE_MISSING_ERR "Map doesn't exist !!!\n"
# define MAP_IS_DIR_ERR "The given file is a directory !!!\n"

typedef struct s_player
{
    int x;
    int y;
    int exist;
    int exit;
    int collectibles;
}   t_player;
typedef struct s_game
{
    char **map;
    int map_width;
    int map_height;
    int map_grid_size;
    int collectibles;
    int exit_is_open;
    t_player player;
} t_game;

// typedef struct s_list
// {
//     char *line;
//     struct s_list *next;
// } t_list;



#endif
