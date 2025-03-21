#ifndef SO_LONG_H
#define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
#include "defs.h"
#include "garbage_collector.h"
// #include "minilibx-linux/mlx.h"
#include <mlx.h>

# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080

# define FULLY_TR 0xFF000000

# define SIZE 64
# define TRUE 1
# define FALSE 0

# define COLL_FRAME 50
# define PLAYER_FRAME 100
# define PLAYER_FRAME_MV 40
# define ENEMY_FRAME 80
# define PLAYER_MOVE 1
# define ENEMY_MOVE 1
# define ENEMY_IDLE_TIMEOUT 1000
# define SEP 5

enum {
	IDLE,
	MOVING
};

enum {
	LEFT,
	RIGHT,
	UP,
	DOWN,
};

enum {
	PLAYER,
	COLLECTIBLE,
	ENEMY,
	EXIT
};

typedef struct s_pos
{
	int x;
	int y;
	int live_x;
	int live_y;
	int old_x;
	int old_y;
} t_pos;

typedef struct s_xpm
{
	void *data;
	int images_count;
	int current_image;
} t_xpm;

typedef struct s_xpm1
{
	void *data[2][4];
	int images_count[2];
	int current_image[2];
} t_xpm1;


typedef struct	s_data {
	void 	*mlx;
	void 	*window;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_direction
{
	int direction;
	struct s_direction *next;
} t_direction;

typedef struct s_player
{
	t_pos pos;
	t_xpm1 img;
	int state;
	t_direction *facing;
	int last_direction;
	int collected_collectibles;
} t_player;

typedef struct s_enemy
{
	t_pos pos;
	t_xpm1 img;
	int state;
	int facing;
	int moves;
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

typedef struct s_cell
{
	t_pos pos;
	char type;
	void *tail;
} t_cell;

typedef struct s_enteties
{
	t_collectible	*collectibles;
	t_enemy			*enemies;
	t_player		player;
	t_exit			exit;
} t_enteties;

typedef struct s_game
{
	t_enteties entities;
	t_data *data;
	t_cell **map;
	int game_status;
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
char **copy_map(t_list **head, int height, int width);

void build_wall(t_game *game, int i, int j);
void build_player(t_game *game, int i, int j);
void build_collectible(t_game *game, int i, int j);
void build_exit(t_game *game, int i, int j);
void build_enemy(t_game *game, int i, int j);
void build_floor(t_game *game, int i, int j);

void init_mlx(t_game *game);
void init_mask_array(t_game *game);
void **get_floor_mask_array();
void *get_xpm_using_mask(int mask_id);
int load_map(t_game *game);

/* Event */
int	close_mlx(t_data *data);
int handle_key_press(int keycode, t_game *game);
int handle_keys_release(int keycode, t_game *game);
int collusion_handle(t_game *game);

int *total_moves();

void free_map_char(char **simple_map);

void append_key(t_game *game, t_direction **head, int direction);
void pop_key(t_game *game, t_direction **head, int direction);

int get_random_moves();
int get_clear_path(t_game *game, t_enemy *enemy);

int ft_abs(int n);

#endif