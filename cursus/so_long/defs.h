#ifndef DEFS_H
#define DEFS_H

/* Player XPM*/
# define PLAYER_PATH "textures/player/output_03.xpm"

# define ENEMY_PATH_ID "textures/enemy/idle_down.xpm"
# define ENEMY_PATH_IU "textures/enemy/idle_up.xpm"
# define ENEMY_PATH_IL "textures/enemy/idle_left.xpm"
# define ENEMY_PATH_IR "textures/enemy/idle_right.xpm"

# define ENEMY_PATH_MD "textures/enemy/move_down.xpm"
# define ENEMY_PATH_MU "textures/enemy/move_up.xpm"
# define ENEMY_PATH_ML "textures/enemy/move_left.xpm"
# define ENEMY_PATH_MR "textures/enemy/move_right.xpm"

# define PLAYER_PATH_ID "textures/player/idle_down.xpm"
# define PLAYER_PATH_IU "textures/player/idle_up.xpm"
# define PLAYER_PATH_IL "textures/player/idle_left.xpm"
# define PLAYER_PATH_IR "textures/player/idle_right.xpm"

# define PLAYER_PATH_MD "textures/player/move_down.xpm"
# define PLAYER_PATH_MU "textures/player/move_up.xpm"
# define PLAYER_PATH_ML "textures/player/move_left.xpm"
# define PLAYER_PATH_MR "textures/player/move_right.xpm"

/* Wall Texture */
# define WALL_PATH "textures/wall.xpm"
# define COINS_PATH "textures/coins.xpm"
# define EXIT_PATH "textures/exit.xpm"

/* Floor Textures */
# define TOP_FLOOR_PATH  "textures/floor/t.xpm"
# define BOTTOM_FLOOR_PATH "textures/floor/b.xpm"
# define LEFT_FLOOR_PATH "textures/floor/l.xpm"
# define RIGHT_FLOOR_PATH "textures/floor/r.xpm"

# define TOP_LEFT_FLOOR_PATH "textures/floor/tl.xpm"
# define TOP_RIGHT_FLOOR_PATH "textures/floor/tr.xpm"
# define BOTTOM_LEFT_FLOOR_PATH "textures/floor/bl.xpm"
# define BOTTOM_RIGHT_FLOOR_PATH "textures/floor/br.xpm"

# define TOP_LEFT_RIGHT_FLOOR_PATH "textures/floor/tlr.xpm"
# define BOTTOM_LEFT_RIGHT_FLOOR_PATH "textures/floor/blr.xpm"
# define LEFT_TOP_BOTTOM_FLOOR_PATH "textures/floor/tbl.xpm"
# define RIGHT_TOP_BOTTOM_FLOOR_PATH "textures/floor/tbr.xpm"

# define FLOOR_PATH "textures/floor/m.xpm"
# define LEFT_RIGHT_FLOOR_PATH "textures/floor/lr.xpm"
# define TOP_BOTTOM_FLOOR_PATH "textures/floor/tb.xpm"
# define CORNERED_FLOOR_PATH "textures/floor/tblr.xpm"
// # define FULL_FLOOR_PATH "textures/floor/full.xpm"


# define ERROR "Error\n^^^^^\\ \n      "
# define USAGE_ERR "Usage: ./so_long [MAP_PATH]\n"
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
# define BIG_MAP_ERR "The map is unplayable !!!\n"

#endif