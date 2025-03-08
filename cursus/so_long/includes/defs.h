#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
# include "../libft/libft.h"

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

typedef enum e_cell_type
{
    WALL,
    SPACE,
    COLLECTABLE,
    PLAYER,
    ENEMY,
    EXIT,
    INVALID
} t_cell_type;

typedef struct s_player
{
    int x;
    int y;
    int exist;
    int exit;
    int collectibles;
}   t_player;

typedef struct s_enemy
{
    int x;
    int y;
    int detecte_player;
}   t_enemy;

typedef struct s_collectable
{
    int x;
    int y;
    int is_collected;
    int is_accessible;
}   t_collectable;

typedef struct s_cell
{
    int x;
    int y;
    t_cell_type type;
    int is_closed;
} t_cell;

typedef struct s_enteties
{
    t_player player;
    t_enemy *enemies;
    t_collectable *collectables;
} t_enteties;

typedef struct s_game
{
    t_cell **map;
    t_enteties enteties;
    int map_width;
    int map_height;
    int map_grid_size;
    int collectibles;
    int exit_is_open;
    t_player player;
} t_game;

typedef struct s_queue
{
    t_list *head;
    t_list *tail;
    int is_empty;
} t_queue;



#endif
