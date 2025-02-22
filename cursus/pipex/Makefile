CC = cc
DEBUG_FLAGS = -fsanitize=address -g3
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
MAKE = make

UTILS = utils/utils.c utils/parser.c garbage_collector/garbage_collector.c \
	utils/executing_command.c utils/path_exractor.c utils/build_command.c \
	utils/file_access.c utils/init_pipex.c utils/error.c utils/process_management.c \
	utils/file_check.c

SRC = src/pipex_mandatory.c
SRC_BONUS = src_bonus/pipex_bonus.c src_bonus/here_doc_bonus.c \
	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJ_OUTILS = $(UTILS:.c=.o)
OBJ_FILES_BONUS = $(SRC_BONUS:.c=.o)

NAME = pipex
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJ_FILES_BONUS) $(OBJ_OUTILS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES_BONUS) $(OBJ_OUTILS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR) bonus

all: bonus

clean:
	$(RM) $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
