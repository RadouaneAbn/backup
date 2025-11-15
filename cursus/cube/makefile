CC = gcc
CFLAGS = -Wall -Wextra -g3
NAME = cube
SRC = main.c mlx_utils.c hundel_keys.c tests.c

INCLUDE = include

MLX_LIB = minilibx-linux/libmlx_Linux.a

SRC_OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRC_OBJ) $(LIBFT) cube.h $(MLX_LIB)
	$(CC) $(CFLAGS) $(SRC_OBJ) -L$(LIBFT_DIR) -Lminilibx-linux -lmlx_Linux -I $(INCLUDE) -Iminilibx-linux -lXext -lX11 -lm -lz -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE) -Iminilibx-linux

bonus: $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR) all

$(MLX_LIB):
	$(MAKE) -C minilibx-linux all

clean:
	$(RM) $(SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus 