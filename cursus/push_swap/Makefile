CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf
MAKE := make

SRC_FILES := $(wildcard *.c stack_calls/*.c) 
OBJ_FILES := $(SRC_FILES:.c=.o)

# NAME := push_swap
NAME := push_swap_new

# LIBFT_DIR = ./libft
# LIBFT_NAME = libft.a

all: $(NAME)

# $(LIBFT_DIR)/$(LIBFT_NAME):
# 	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) -g $^ -o $@

clean:
	$(RM) $(OBJ_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
.SECONDARY: $(OBJ_FILES)
