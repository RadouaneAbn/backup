CC := cc
CFLAGS := -Wall -Wextra -Werror -g
RM := rm -rf

UTILS := utils/count_args.c utils/init_stack.c utils/push_calls.c utils/reverse_rotate_calls.c utils/rotate_calls.c \
	utils/swap_calls.c utils/utils.c utils/convert.c utils/exit.c utils/stack_utils.c utils/validation.c utils/free_stacks.c

SRC := src/calc_score.c src/sort_stack.c src/moves.c src/push_swap.c src/utils_2.c src/utils.c 
BONUS := get_next_line/get_next_line.c get_next_line/get_next_line_utils.c src_bonus/checker_bonus.c \
	src_bonus/checker_utils_bonus.c src_bonus/instructions_utils_bonus.c

OBJ_FILES := $(UTILS:.c=.o) $(SRC:.c=.o)
OBJ_FILES_BONUS := $(UTILS:.c=.o) $(BONUS:.c=.o)

NAME := push_swap
BONUS_NAME := checker

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJ_FILES_BONUS)
	$(CC) $(CFLAGS) $^ -o $(BONUS_NAME)

all: $(NAME) bonus

clean:
	$(RM) $(OBJ_FILES) $(OBJ_FILES_BONUS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean
.SECONDARY: $(OBJ_FILES) $(OBJ_FILES_BONUS)
