#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"

#define FLOOR_FILES_COUNT 1
#define FLOOR_PATH "xpm/f_1.xpm"

#define WALL_FILES_COUNT 1
#define WALL_PATH "xpm/w_t_2.xpm"

typedef struct s_tail
{
	void *tail;
	int size;
} t_tail;


enum {
	PLAYER,
	COLLECTIBLE,
	ENEMY,
	EXIT,
};

typedef struct s_entity
{
	void *xpm;
	float x;
	float y;
	int type;
} t_entity;

typedef struct s_entities
{
	t_entity player;
} t_entities;

enum e_tail_xpm
{
	WALL,
	FLOOR,
};

enum e_tail_pos
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT,
};

#define W_MAP 16
#define H_MAP 12
#define SIZE 64
#define FULLY_TR 0xFF000000

typedef struct s_tails
{
	t_tail *tail;
	int size;
} t_tails;



// t_tail **load_images(void *mlx)
// {
//     t_tail **tails;

//     tails = malloc(sizeof(t_tail *) * 2);
//     tails[WALL] = malloc(sizeof(t_tail));
//     tails[WALL]->size = WALL_FILES_COUNT;
//     tails[WALL]->tail = mlx_xpm_file_to_image(mlx, WALL_PATH, &(64), &(64));
//     tails[FLOOR] = malloc(sizeof(t_tail));
//     tails[FLOOR]->size = FLOOR_FILES_COUNT;
//     tails[FLOOR]->tail = mlx_xpm_file_to_image(mlx, FLOOR_PATH, &(64), &(64));

//     return (tails);
// }

typedef struct	s_data {
	void *mlx;
	void *win;
	void *floor;
	void *wall[8];
	void *exit[2];
	void *colls[3];
	t_entity player;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void copy_xpm_to_image(t_data *img, int i, int j, void *xpm)
{
	t_data data;
	char *current_cell;
	int color;
	int x, y;

	// printf("copy tail: [%d, %d][%d, %d]\n", i, j, i + 64, j + 64);
	current_cell = mlx_get_data_addr(xpm, &data.bits_per_pixel, &data.line_length, &data.endian);
	y = 0;
	while (y < 64)
	{
		x = 0;
		while (x < 64)
		{
			color = *(unsigned int *)(current_cell + (y * data.line_length + x * (data.bits_per_pixel / 8)));
			if (color != FULLY_TR) // Assume white is the background
				my_mlx_pixel_put(img, x + i, y + j, color);
			// printf("pix[%d,%d]\n", i + x, j + y);
			x++;
		}
		y++;
	}
}

void fill_image(t_data *data, int size)
{
	int i = 0, j = 0;
	while (i < W_MAP)
	{
		j = 0;
		while (j < H_MAP)
		{
			if (i == 0 && j == 0)
				copy_xpm_to_image(data, i * size, j * size, data->wall[LEFT]);
			else if (i == 0 && (j == H_MAP - 1))
				copy_xpm_to_image(data, i * size, j * size , data->wall[BOTTOM_LEFT]);
			else if ((i == W_MAP - 1) && (j == H_MAP - 1))
				copy_xpm_to_image(data, i * size, j * size , data->wall[BOTTOM_RIGHT]);
			else if ((i == W_MAP - 1) && j == 0)
				copy_xpm_to_image(data, i * size, j * size , data->wall[RIGHT]);
			else if (i == 0)
				copy_xpm_to_image(data, i * size, j * size , data->wall[LEFT]);
			else if (i == W_MAP - 1)
				copy_xpm_to_image(data, i * size, j * size , data->wall[RIGHT]);
			else if (j == 0)
				copy_xpm_to_image(data, i * size, j * size , data->wall[TOP]);
			else if (j == H_MAP - 1)
				copy_xpm_to_image(data, i * size, j * size , data->wall[BOTTOM]);
			else
				copy_xpm_to_image(data, i * size, j * size , data->floor);
			j++;
		}
		i++;
	}
}

void mlx_put_player_in_map(t_data *data)
{
	copy_xpm_to_image(data, (data->player.x + 64), (data->player.y + 64), data->player.xpm);
}

void mlx_put_exit_in_map(t_data *data)
{
	copy_xpm_to_image(data, (64 * (W_MAP - 2)), (64 * (H_MAP - 2)), data->exit[0]);
	copy_xpm_to_image(data, (64 * (W_MAP - 3)), (64 * (H_MAP - 2)), data->exit[1]);
}

int	close_mlx(t_data *vars)
{
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->floor);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0); // exit is nesseccery to stop the mlx loop
	return (0);
}

void put_walls_floor(t_data img, int size)
{
	int i = 0, j;

	while (i < W_MAP)
	{
		j = 0;
		while (j < H_MAP)
		{
			if (i == 0 && j == 0)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[LEFT], i * size, j * size);
			else if (i == 0 && (j == H_MAP - 1))
				mlx_put_image_to_window(img.mlx, img.win , img.wall[BOTTOM_LEFT], i * size, j * size);
			else if ((i == W_MAP - 1) && (j == H_MAP - 1))
				mlx_put_image_to_window(img.mlx, img.win , img.wall[BOTTOM_RIGHT], i * size, j * size);
			else if ((i == W_MAP - 1) && j == 0)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[RIGHT], i * size, j * size);
			else if (i == 0)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[LEFT], i * size, j * size);
			else if (i == W_MAP - 1)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[RIGHT], i * size, j * size);
			else if (j == 0)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[TOP], i * size, j * size);
			else if (j == H_MAP - 1)
				mlx_put_image_to_window(img.mlx, img.win , img.wall[BOTTOM], i * size, j * size);
			else
				mlx_put_image_to_window(img.mlx, img.win , img.floor, i * size, j * size);
			j++;
		}
		i++;
	}
}

void put_exit(t_data img, int size)
{
	mlx_put_image_to_window(img.mlx, img.win , img.exit[0], 1 * size, 1 * size);
	mlx_put_image_to_window(img.mlx, img.win , img.exit[0], 2 * size, 1 * size);
	mlx_put_image_to_window(img.mlx, img.win , img.exit[1], 2 * size, 1 * size);
}

int moves_count()
{
	static int count;

	count++;
	return (count);
}

#define MOVING_PIX 8
#define OFFSET_PIX 4


void move_right(t_data *data)
{
	printf("%-3d| RIGHT\n", moves_count());
	int i = 0;

	while (i < OFFSET_PIX)
	{
		data->player.x += MOVING_PIX;
		fill_image(data, SIZE);
		mlx_put_exit_in_map(data);
		mlx_put_player_in_map(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		i++;
	}
}

void move_left(t_data *data)
{
	printf("%-3d| LEFT\n", moves_count());
	int i = 0;

	while (i < OFFSET_PIX)
	{
		data->player.x -= MOVING_PIX;
		fill_image(data, SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_put_exit_in_map(data);
		mlx_put_player_in_map(data);
		i++;
	}
}

void move_up(t_data *data)
{
	printf("%-3d| UP\n", moves_count());
	int i = 0;

	while (i < OFFSET_PIX)
	{
		data->player.y -= MOVING_PIX;
		fill_image(data, SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_put_exit_in_map(data);
		mlx_put_player_in_map(data);
		i++;
	}
}

void move_down(t_data *data)
{
	printf("%-3d| DOWN\n", moves_count());
	int i = 0;

	while (i < OFFSET_PIX)
	{
		data->player.y += MOVING_PIX;
		fill_image(data, SIZE);
		mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
		mlx_put_exit_in_map(data);
		mlx_put_player_in_map(data);
		i++;
	}
}

int handle_keys(int keycode, t_data *vars)
{
	if (keycode == XK_w)
		move_up(vars);
	else if (keycode == XK_s)
		move_down(vars);
	else if (keycode == XK_d)
		move_right(vars);
	else if (keycode == XK_a)
		move_left(vars);
	else if (keycode == XK_Up)
		move_up(vars);
	else if (keycode == XK_Down)
		move_down(vars);
	else if (keycode == XK_Right)
		move_right(vars);
	else if (keycode == XK_Left)
		move_left(vars);
	else if (keycode == XK_Escape)
		close_mlx(vars);
	return (0);
}

void init_entities(t_entity *player)
{
	player->x = 1;
	player->y = 1;
	player->type = PLAYER;


}

int	main(void)
{
	t_data	img;
	t_entity player;
	int size = 64;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 64*W_MAP, 64*H_MAP, "Hello world!");
	img.img = mlx_new_image(img.mlx, 64*W_MAP, 64*H_MAP);
	img.floor = mlx_xpm_file_to_image(img.mlx, FLOOR_PATH, &size, &size);
	img.wall[LEFT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_l_1.xpm", &size, &size);
	img.wall[RIGHT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_r_1.xpm", &size, &size);
	img.wall[TOP] = mlx_xpm_file_to_image(img.mlx, "xpm/w_t_2.xpm", &size, &size);
	img.wall[BOTTOM] = mlx_xpm_file_to_image(img.mlx, "xpm/w_b_1.xpm", &size, &size);
	img.wall[TOP_LEFT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_tl_1.xpm", &size, &size);
	img.wall[TOP_RIGHT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_tr_1.xpm", &size, &size);
	img.wall[BOTTOM_LEFT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_bl_1.xpm", &size, &size);
	img.wall[BOTTOM_RIGHT] = mlx_xpm_file_to_image(img.mlx, "xpm/w_br_1.xpm", &size, &size);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.exit[0] = mlx_xpm_file_to_image(img.mlx, "xpm/exit.xpm", &size, &size);
	img.exit[1] = mlx_xpm_file_to_image(img.mlx, "xpm/exit_door.xpm", &size, &size);
	img.player.xpm = mlx_xpm_file_to_image(img.mlx, "xpm/p.xpm", &size, &size);
	/*
	// this while loop alters the image saved in the img.img
	while (i < 10)
	{
		// mlx_pixel_put(mlx, img.win, 65 + i, 65 + i, 0x00FF0000);
		my_mlx_pixel_put(&img, i, i, 0x00FF0000);
		i++;
	}
	*/
	init_entities(&player);
	// put_walls_floor(img, size);
	// put_exit(img, size);
	// mlx_put_image_to_window(img.mlx, img.win , img.player, 15 * size, 1 * size);
	fill_image(&img, size);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_put_player_in_map(&img);
	mlx_put_exit_in_map(&img);

	mlx_hook(img.win, 17, 0, close_mlx, &img);
	mlx_hook(img.win, 2, 1L << 0, handle_keys, &img);
	// mlx_key_hook(img.win, close_mlx, &img);
	// mlx_key_hook(img.win, handle_keys, &img);
	mlx_loop(img.mlx);
}
