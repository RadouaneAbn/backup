#include "cube.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_cell(t_data *data, t_pos pos, int color)
{
	int				x;
	int				y;

	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			my_mlx_pixel_put(data, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

void	copy_xpm_pixels_to_window(t_data *data, t_pos pos, int frame)
{
	unsigned int	color;
	int				x;
	int				y;

	(void) frame;
	y = 0;
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
			color = 0xadabaa;
			my_mlx_pixel_put(data, pos.x + x, pos.y + y, color);
			x++;
		}
		y++;
	}
}

void	close_mlx(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

int	exit_game(t_game *game)
{

	mlx_loop_end(game->data->mlx);
	close_mlx(game->data);
	printf("exit\n");
	exit(0);
}

void draw_horizontal_line(t_data *data, int start_x, int start_y, int length, int thickness, int color)
{
    int x, y;
    
    y = 0;
    while (y < thickness)
    {
        x = 0;
        while (x < length)
        {
            my_mlx_pixel_put(data, start_x + x, start_y + y, color);
            x++;
        }
        y++;
    }
}

void draw_vertical_line(t_data *data, int start_x, int start_y, int length, int thickness, int color)
{
    int x, y;
    
    x = 0;
    while (x < thickness)
    {
        y = 0;
        while (y < length)
        {
            my_mlx_pixel_put(data, start_x + x, start_y + y, color);
            y++;
        }
        x++;
    }
}