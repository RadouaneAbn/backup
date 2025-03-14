CC = cc
CDEBUG_FLAGS = -fsanitize=address 
# CFLAGS = -Wall -Wextra -Werror -g3 

NAME = so_long
SRC = src/so_long.c garbage_collector/garbage_collector.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	src/file.c src/error.c src/queue.c

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