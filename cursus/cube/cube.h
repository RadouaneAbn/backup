#ifndef CUBE_H
# define CUBE_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <mlx.h>
#include "libft/libft.h"

#define SIZE 64
#define STEP_P  1
#define PI 3.14159265359
#define CAM_A 10
#define ROTATE_SPEED 0.01

#define MAP_BORDER_THICKNESS 3

typedef enum e_direction
{
	UP_BUTTON = 119,
	DOWN_BUTTON = 115,
	LEFT_BUTTON = 97,
	RIGHT_BUTTON = 100,
	LEFT_ARROW = 65361,
	RIGHT_ARROW = 65363,
	ESCAPE = 65307
} t_direction;


typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef double t_angle;

typedef struct s_move
{
	int now;
	int before;
} t_move;

typedef struct s_player
{
	t_pos pos;
	double pdx;
	double pdy;
	t_angle player_angle;
	t_move walk_direction;
	t_move rotation_direction;
	t_move side_direction;
} t_player;

typedef struct s_data
{
	void				*mlx;
	void				*window;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_length;
	int					endian;
}						t_data;

typedef struct s_game
{
    t_data *data;
	t_player player;
    char **map;
    int map_width;
    int map_height;
} t_game;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	copy_xpm_pixels_to_window(t_data *data, t_pos pos, int frame);
int	exit_game(t_game *game);
void	color_cell(t_data *data, t_pos pos, int color);
int	handle_key_press(int keycode, t_game *game);
int	handle_keys_release(int keycode, t_game *game);


void draw_horizontal_line(t_data *data, int start_x, int start_y, int length, int thickness, int color);
void draw_vertical_line(t_data *data, int start_x, int start_y, int length, int thickness, int color);


#endif