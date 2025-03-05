CC := cc
CFLAGS := -Wall -Wextra -Werror -g
RM := rm -rf
MAKE := make

UTILS := utils/utils.c utils/clean.c utils/parser.c garbage_collector/garbage_collector.c \
	test/malloc_test.c

SRC := src/pipex.c
# SRC_BONUS := src_bonus/pipex_bonus.c

OBJ_FILES := $(SRC:.c=.o)
OBJ_OUTILS := $(UTILS:.c=.o)
# OBJ_FILES_BONUS := $(SRC_BONUS:.c=.o)

TEST := test/print.c

NAME := pipex
NAME_BONUS := pipex
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a


$(NAME): $(OBJ_FILES) $(OBJ_OUTILS) $(LIBFT) $(TEST)
	$(CC) $^ -L$(LIBFT_DIR) -lft -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)


clean:
	$(RM) $(OBJ_FILES) $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ_FILES) $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
