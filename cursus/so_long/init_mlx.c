#include "so_long.h"
// #include "minilibx-linux/mlx_int.h"

int	close_mlx(t_data *data)
{
	mlx_do_key_autorepeaton(data->mlx);
    // free and destroy all images and windows
    mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->window);
	mlx_destroy_display(data->mlx);
	// free(data->mlx);
	exit(0); // exit is nesseccery to stop the mlx loop
}

void init_mlx(t_game *game)
{
	game->data = ft_smalloc(sizeof(t_data));
    game->data->mlx = mlx_init();
    game->data->window = mlx_new_window(game->data->mlx, SIZE * game->map_width,
                                        SIZE * game->map_height, "so_long");
    game->data->img = mlx_new_image(game->data->mlx, SIZE * game->map_width,
                                        SIZE * game->map_height);
	game->data->addr = mlx_get_data_addr(game->data->img, &game->data->bits_per_pixel, &game->data->line_length,
								&game->data->endian);
}
