CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
MAKE = make

UTILS = utils/utils.c utils/clean.c utils/parser.c garbage_collector/garbage_collector.c \
	utils/executing_command.c utils/path_exractor.c utils/build_command.c \
	utils/file_access.c utils/init_pipex.c utils/error.c utils/process_management.c

ENTRY_FILE = pipex.c

SRC = src/pipex_mandatory.c
SRC_BONUS = src_bonus/pipex_bonus.c

OBJ_ENTRY = $(ENTRY_FILE:.c=.o)
OBJ_OUTILS = $(UTILS:.c=.o)
OBJ_FILES_BONUS = $(SRC_BONUS:.c=.o)

NAME = pipex
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

$(NAME): $(OBJ_FILES_BONUS) $(OBJ_OUTILS) $(OBJ_ENTRY) $(LIBFT)
	$(CC) $(OBJ_FILES_BONUS) $(OBJ_OUTILS) $(OBJ_ENTRY) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME)

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

all: bonus

clean:
	$(RM) $(OBJ_FILES) $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
.SECONDARY: $(OBJ_FILES) $(OBJ_OUTILS) $(OBJ_FILES_BONUS)
