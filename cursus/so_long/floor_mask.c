#include "so_long.h"


void **get_floor_mask_array()
{
	static void *floor_mask_xpm[16];

	return (floor_mask_xpm);
}

void init_mask_array(t_game *game)
{
	void **masks;
    int size;

    size = SIZE;
	int i = 0;
	masks = get_floor_mask_array();
	masks[0] = mlx_xpm_file_to_image(game->data->mlx, FLOOR_PATH, &size, &size);
	masks[1] = mlx_xpm_file_to_image(game->data->mlx, TOP_FLOOR_PATH, &size, &size);
	masks[2] = mlx_xpm_file_to_image(game->data->mlx, BOTTOM_FLOOR_PATH, &size, &size);
	masks[3] = mlx_xpm_file_to_image(game->data->mlx, TOP_BOTTOM_FLOOR_PATH, &size, &size);
	masks[4] = mlx_xpm_file_to_image(game->data->mlx, LEFT_FLOOR_PATH, &size, &size);
	masks[5] = mlx_xpm_file_to_image(game->data->mlx, TOP_LEFT_FLOOR_PATH, &size, &size);
	masks[6] = mlx_xpm_file_to_image(game->data->mlx, BOTTOM_LEFT_FLOOR_PATH, &size, &size);
	masks[7] = mlx_xpm_file_to_image(game->data->mlx, LEFT_TOP_BOTTOM_FLOOR_PATH, &size, &size);
	masks[8] = mlx_xpm_file_to_image(game->data->mlx, RIGHT_FLOOR_PATH, &size, &size);
	masks[9] = mlx_xpm_file_to_image(game->data->mlx, TOP_RIGHT_FLOOR_PATH, &size, &size);
	masks[10] = mlx_xpm_file_to_image(game->data->mlx, BOTTOM_RIGHT_FLOOR_PATH, &size, &size);
	masks[11] = mlx_xpm_file_to_image(game->data->mlx, RIGHT_TOP_BOTTOM_FLOOR_PATH, &size, &size);
	masks[12] = mlx_xpm_file_to_image(game->data->mlx, LEFT_RIGHT_FLOOR_PATH, &size, &size);
	masks[13] = mlx_xpm_file_to_image(game->data->mlx, TOP_LEFT_RIGHT_FLOOR_PATH, &size, &size);
	masks[14] = mlx_xpm_file_to_image(game->data->mlx, BOTTOM_LEFT_RIGHT_FLOOR_PATH, &size, &size);
	masks[15] = mlx_xpm_file_to_image(game->data->mlx, CORNERED_FLOOR_PATH, &size, &size);
}

void *get_xpm_using_mask(int mask_id)
{
	void **masks;

	masks = get_floor_mask_array();
	return (masks[mask_id]);
}