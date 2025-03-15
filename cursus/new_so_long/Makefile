CC = cc
CDEBUG_FLAGS = -fsanitize=address 
# CFLAGS = -Wall -Wextra -Werror -g3 

NAME = so_long
SRC = so_long.c build_game_entities.c error.c flood_fill.c \
	free_functions.c garbage_collector.c open_file.c read_map.c \
	validate_map.c

SRC_OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a

$(NAME): $(SRC_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	$(RM) $(SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

queue: src/queue.c $(LIBFT)
	$(CC) src/queue.c -L$(LIBFT_DIR) -lft  -o $@

MLX_SRC = src/mlx_test.c
MLX_OBJ = src/mlx_test.o

mlx_test: $(MLX_OBJ) $(MLX)
	$(CC) $(MLX_OBJ) -L$(MLX_DIR) -lm -lmlx -lXext -lX11 -o win

$(MLX):
	$(MAKE) -C $(MLX_DIR)

re: fclean all