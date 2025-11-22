CC = cc -I/usr/include -Imlx_linux -O3
CFLAGS = -Wall -Wextra -Werror -g3
NAME = cube
SRC = main.c mlx_utils.c hundel_keys.c tests.c


SRC_OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(SRC_OBJ) $(LIBFT) cube.h
	$(CC) $(CFLAGS) $(SRC_OBJ) -L$(LIBFT_DIR) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -lft -o $(NAME)

bonus: $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(RM) $(SRC_OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all 