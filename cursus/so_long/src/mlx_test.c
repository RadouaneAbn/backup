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
    void *player;
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

void copy_xpm_to_image(t_data img, int i, int j, void *xpm)
{
    t_data data;
    char *current_cell;
    int color;
    int x, y;

    x = i;
    current_cell = mlx_get_data_addr(xpm, &data.bits_per_pixel, &data.line_length, &data.endian);
    while (x < i + 64)
    {
        y = j;
        while (y < j + 64)
        {
            color = *(unsigned int *)(current_cell + (x * data.line_length + j * (data.line_length / 8)));
            if (color != 0x000000) // Assume white is the background
                my_mlx_pixel_put(&img, y, x, color);
            y++;
        }
        x++;
    }
}

void fill_image(t_data data, int size)
{
int i = 0, j;

    while (i < 17)
    {
        j = 0;
        while (j < 13)
        {
            if (i == 0 && j == 0)
                copy_xpm_to_image(data, i * size, j * size , data.wall[LEFT]);
            else if (i == 0 && j == 12)
                copy_xpm_to_image(data, i * size, j * size , data.wall[BOTTOM_LEFT]);
            else if (i == 16 && j == 12)
                copy_xpm_to_image(data, i * size, j * size , data.wall[BOTTOM_RIGHT]);
            else if (i == 16 && j == 0)
                copy_xpm_to_image(data, i * size, j * size , data.wall[RIGHT]);
            else if (i == 0)
                copy_xpm_to_image(data, i * size, j * size , data.wall[LEFT]);
            else if (i == 16)
                copy_xpm_to_image(data, i * size, j * size , data.wall[RIGHT]);
            else if (j == 0)
                copy_xpm_to_image(data, i * size, j * size , data.wall[TOP]);
            else if (j == 12)
                copy_xpm_to_image(data, i * size, j * size , data.wall[BOTTOM]);
            else
                copy_xpm_to_image(data, i * size, j * size , data.floor);
            j++;
        }
        i++;
    }
}

int	close_mlx(int keycode, t_data *vars)
{
     if (keycode == XK_Escape)
    {
        printf("KeyCode: %d\n", keycode);
        mlx_destroy_image(vars->mlx, vars->img);
        mlx_destroy_window(vars->mlx, vars->win);
        mlx_destroy_image(vars->mlx, vars->floor);
        mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        exit(0);
    }
	return (0);
}

void put_walls_floor(t_data img, int size)
{
    int i = 0, j;

    while (i < 17)
    {
        j = 0;
        while (j < 13)
        {
            if (i == 0 && j == 0)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[LEFT], i * size, j * size);
            else if (i == 0 && j == 12)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[BOTTOM_LEFT], i * size, j * size);
            else if (i == 16 && j == 12)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[BOTTOM_RIGHT], i * size, j * size);
            else if (i == 16 && j == 0)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[RIGHT], i * size, j * size);
            else if (i == 0)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[LEFT], i * size, j * size);
            else if (i == 16)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[RIGHT], i * size, j * size);
            else if (j == 0)
                mlx_put_image_to_window(img.mlx, img.win , img.wall[TOP], i * size, j * size);
            else if (j == 12)
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

int	main(void)
{
	t_data	img;
    int size = 64;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, 64*17, 64*13, "Hello world!");
	img.img = mlx_new_image(img.mlx, 64*17, 64*13);
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
    img.exit[0] = mlx_xpm_file_to_image(img.mlx, "exit.xpm", &size, &size);
    img.exit[1] = mlx_xpm_file_to_image(img.mlx, "xpm/exit_door.xpm", &size, &size);
    img.player = mlx_xpm_file_to_image(img.mlx, "xpm/p.xpm", &size, &size);
    /*
    // this while loop alters the image saved in the img.img
    while (i < 10)
    {
        // mlx_pixel_put(mlx, img.win, 65 + i, 65 + i, 0x00FF0000);
	    my_mlx_pixel_put(&img, i, i, 0x00FF0000);
        i++;
    }
    */

    // put_walls_floor(img, size);
    // put_exit(img, size);
    fill_image(img, size);
    // mlx_put_image_to_window(img.mlx, img.win , img.player, 15 * size, 1 * size);
    mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);

    // mlx_hook(img.win, 2, 1L<<0, close_mlx, &img);
    mlx_key_hook(img.win, close_mlx, &img);
	mlx_loop(img.mlx);
}
