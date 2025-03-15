#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
#include "messages.h"
#include "garbage_collector.h"

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define SIZE 64
# define TRUE 1
# define FALSE 0

enum {
	PLAYER,
	COLLECTIBLE,
	ENEMY,
	EXIT,
};

typedef struct s_pos
{
    int x;
    int y;
    int live_x;
    int live_y;
} t_pos;

typedef struct s_xpm
{
    void *data;
    int images_count;
    int current_image;
} t_xpm;


typedef struct	s_data {
	void *mlx;
	void *win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_player
{
    t_pos pos;
    t_xpm img;
    int collected_collectibles;
} t_player;

typedef struct s_enemy
{
    t_pos pos;
    t_xpm img;
} t_enemy;

typedef struct s_exit
{
    t_pos pos;
    t_xpm img;
    int is_open;
} t_exit;

typedef struct s_collectible
{
    t_pos pos;
    t_xpm img;
    int is_collected;
} t_collectible;

typedef struct s_entity
{
    int x;
    int y;
    int live_x;
    int live_y;
    int is_moving;
    t_xpm img;
} t_entity;

typedef struct s_cell
{
    int x;
    int y;
    char type;
    void *tail;
} t_cell;

typedef struct s_enteties
{
    t_exit *exit;
    t_collectible *collectibles;
    t_player player;
    t_enemy *enemies;
} t_enteties;

typedef struct s_game
{
    t_enteties entities;
    t_data data;
    t_cell **map;
    int map_width;
    int map_height;
    int total_collectible;
    int total_enemy;
    int total_player;
    int total_exit;
    int player_has_access_to_collectibles;
    int player_has_access_to_exit;
} t_game;

/* Function Definitions */
void map_components_invalide(int player, int map_exit, int collectibles);
void map_access_invalide(t_game *game);
void exit_error(int exit_status, char *msg);

int open_file(char *map_path);
int read_map(t_list **head, int fd);
void validate_map(t_game *game, char **map);
void flood_fill_full(char **map, int x, int y, t_game *game);
void build_game_dimentions(t_game *game, t_list **head);

void free_map_char(char **simple_map);

#endif