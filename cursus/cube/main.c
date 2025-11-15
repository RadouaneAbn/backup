#include "cube.h"
#include "tests.h"

int	load_map(t_game *game);

t_pos find_player_pos(char **map)
{
	int i, j;

	j = 0;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'P')
				return ((t_pos){i * SIZE + SIZE / 2,j * SIZE + SIZE / 2});
			i++;
		}
		j++;
	}
	return ((t_pos){0,0});
}

void init_map(char **map, t_game *game)
{
	game->map_height = 0;
	game->map_width = 0;
	while (map[game->map_height])
		game->map_height++;
	while (map[0][game->map_width])
		game->map_width++;
	ft_bzero(&game->player, sizeof(t_player));
	game->player.pos = find_player_pos(map);
	game->player.player_angle = PI / 2;
	// game->player.pdx = cos(game->player.player_angle) * STEP_P;
	// game->player.pdy = sin(game->player.player_angle) * STEP_P;
	// printf("Player Pos: {%d, %d}\n", game->player.pos.x, game->player.pos.y);
	game->map = map;
}

void	init_mlx(t_game *game)
{
	game->data = malloc(sizeof(t_data));
	game->data->mlx = mlx_init();
	game->data->window = mlx_new_window(game->data->mlx, SIZE * game->map_width,
			SIZE * game->map_height, "so_long");
	game->data->img = mlx_new_image(game->data->mlx, SIZE * game->map_width,
			SIZE * game->map_height);
	game->data->addr = mlx_get_data_addr(game->data->img,
			&game->data->bits_per_pixel, &game->data->line_length,
			&game->data->endian);
}

static void	load_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		// printf("map[%d]: %s\n", i, game->map[i]);
		j = 0;
		while (j < game->map_width)
		{
			if (game->map[i][j] == '1')
				color_cell(game->data, (t_pos){.x=j*SIZE,.y=i*SIZE}, 0x818589);
			else
				color_cell(game->data, (t_pos){.x=j*SIZE,.y=i*SIZE}, 0xE5E4E2);
			j++;
		}
		i++;
	}

	i = 0;
	while (i < game->map_height)
    {
        j = 0;
        while (j < game->map_width)
        {
            if (game->map[i][j] == '1')
            {
                if (i == 0 || game->map[i-1][j] != '1')
                    draw_horizontal_line(game->data, j*SIZE, i*SIZE, SIZE, MAP_BORDER_THICKNESS, 0x0);
                if (i == game->map_height-1 || game->map[i+1][j] != '1')
                    draw_horizontal_line(game->data, j*SIZE, (i+1)*SIZE-1, SIZE, MAP_BORDER_THICKNESS, 0x0);
                if (j == 0 || game->map[i][j-1] != '1')
                    draw_vertical_line(game->data, j*SIZE, i*SIZE, SIZE, MAP_BORDER_THICKNESS, 0x0);
                if (j == game->map_width-1 || game->map[i][j+1] != '1')
                    draw_vertical_line(game->data, (j+1)*SIZE-1, i*SIZE, SIZE, MAP_BORDER_THICKNESS, 0x0);
            }
            j++;
        }
        i++;
    }
}

void	draw_player(t_data *data, t_pos pos, int color)
{
    int		x;
    int		y;
    int		radius;
    int		dx;
    int		dy;
    int		distance_squared;

    radius = 10;
    y = -radius;
    while (y <= radius)
    {
        x = -radius;
        while (x <= radius)
        {
            dx = x;
            dy = y;
            distance_squared = dx * dx + dy * dy;
            if (distance_squared <= radius * radius)
            {
                my_mlx_pixel_put(data, pos.x + x, pos.y + y, color);
            }
            x++;
        }
        y++;
    }
}

void draw_direction(t_game *game, int color)
{
	int i = 0;
	int x, y;
	int tk = 2; // line thickness
	int dx, dy;

	while (i < 400)
	{
		dx = -tk;
		while (dx <= tk)
		{
			dy = -tk;
			while (dy <= tk)
			{
				x = game->player.pos.x - ((i * (cos(game->player.player_angle) * 8) - dx) / 64);
				y = game->player.pos.y - ((i * (sin(game->player.player_angle) * 8) - dy) / 64);
				my_mlx_pixel_put(game->data, x, y, color);
				dy++;
			}
			dx++;
		}
		
		i++;
	}
}

// void draw_directions(t_game *game, int color)
// {
// 	double i = game->player.pa - CAM_A;
// 	double pdx, pdy;

// 	if (i > 2 * PI) { i -= 2 * PI; }
// 	if (i < 0) 		{ i += 2 * PI; }
// 	// while loop to create rayes (point of view)
// 	// while (i <= game->player.pa)
// 	// {
// 	// 	pdx = cos(game->player.pa) * STEP_P - i;
// 	// 	pdy = sin(game->player.pa) * STEP_P - i;
// 	// 	draw_direction(game, pdx, pdy, color);
// 	// 	i+=0.3;
// 	// }

// 	pdx = cos(game->player.pa) * 8;
// 	pdy = sin(game->player.pa) * 8;
// 	draw_direction(game, pdx, pdy, color);
// }


void load_player(t_game *game)
{
	draw_direction(game, 0xfb2b2b);
	// draw_player_direction_line(game, 0x6082B6);
	// draw_directions(game, 0xf55142);
	draw_player(game->data, game->player.pos, 0x6082B6);
}

void update_player(t_game *game, t_player *player)
{
	// do the logic to move the player
	(void) game;
	double pdx, pdy;

	player->player_angle += player->rotation_direction.now * ROTATE_SPEED;
	if (player->player_angle > 2 * PI)
		player->player_angle -= 2 * PI;
	else if (player->player_angle < 0)
		player->player_angle += 2 * PI;
	
	pdx = 0;
	pdy = 0;

	// printf("angle: %f\n", player->player_angle);
	// printf("cos: %f, sin: %f\n", cos(player->player_angle), sin(player->player_angle));
	// if (player->walk_direction.now != 0 && player->side_direction.now == 0)
	// {
	// 	pdx = cos(player->player_angle) * (player->walk_direction.now * STEP_P);
	// 	pdy = sin(player->player_angle) * (player->walk_direction.now * STEP_P);
	// }
	// else if (player->walk_direction.now == 0 && player->side_direction.now != 0)
	// {
	// 	pdx = cos(player->player_angle + PI / 2) * (player->side_direction.now);
	// 	pdy = sin(player->player_angle + PI / 2) * (player->side_direction.now);
	// }

    pdx += cos(player->player_angle) * STEP_P * player->walk_direction.now;
    pdy += sin(player->player_angle) * STEP_P * player->walk_direction.now ;
    // pdx += cos(player->player_angle + PI / 2) * STEP_P * player->side_direction.now;
    // pdy += sin(player->player_angle + PI / 2) * STEP_P * player->side_direction.now;

	player->pos.x += (int)(pdx / 3);
	player->pos.y += (int)(pdy / 3);
	}

int	load_map(t_game *game)
{
	update_player(game, &game->player);
	// printf("[%d,%d]->{%f}\n", game->player.pos.x, game->player.pos.y, game->player.player_angle);
	load_walls(game);
	load_player(game);
	mlx_put_image_to_window(game->data->mlx, game->data->window, game->data->img, 0, 0);
	// test_keys(game);

	return (0);
}

void	start_game(t_game *game)
{
	mlx_do_key_autorepeatoff(game->data->mlx);
	mlx_hook(game->data->window, 2, 1L << 0, handle_key_press, game);
	mlx_hook(game->data->window, 3, 1L << 1, handle_keys_release, game);
	mlx_hook(game->data->window, 17, 0, exit_game, game);
	mlx_loop_hook(game->data->mlx, load_map, (void *)game);
	mlx_loop(game->data->mlx);
}

int main()
{
	t_game game;
	char *map[] = {
		"111111111111",
		"1P1000000001",
		"101000000101",
		"101000000001",
		"100001110101",
		"100000000101",
		"111111111111",
		NULL
	};
	init_map(map, &game);
	init_mlx(&game);
	start_game(&game);
	return (0);
}