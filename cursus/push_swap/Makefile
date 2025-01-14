CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf
MAKE := make

SRC_FILES := count_args.c init_stack.c push_calls.c reverse_rotate_calls.c rotate_calls.c \
	swap_calls.c utils.c convert.c exit.c stack_utils.c validation.c free_stacks.c

SRC_FILES_MANDATORY := calc_score.c sort_stack.c moves.c push_swap.c utils_2.c 
SRC_FILES_BONUS := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	bonus/checker.c bonus/ft_strcmp.c

OBJ_FILES := $(SRC_FILES:.c=.o) $(SRC_FILES_MANDATORY:.c=.o)
OBJ_FILES_BONUS := $(SRC_FILES:.c=.o) $(SRC_FILES_BONUS:.c=.o)

NAME := push_swap
BONUS_NAME := checker

all: $(NAME)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(OBJ_FILES_BONUS)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

clean:
	$(RM) $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean
.SECONDARY: $(OBJ_FILES) $(OBJ_FILES_BONUS)
