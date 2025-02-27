CC = cc
CDEBUG_FLAGS = -fsanitize=address 
CFLAGS = -Wall -Wextra -Werror -g3 

NAME = so_long
SRC = src/so_long.c garbage_collector/garbage_collector.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

SRC_OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

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

re: fclean all