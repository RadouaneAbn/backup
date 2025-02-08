CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

# UTILS := src/pipex_utils.c
# SRC := src/pipex.c

# OBJ_FILES := $(UTILS:.c=.o) $(SRC:.c=.o)

NAME := pipex

all: $(NAME)

$(NAME): src/pipex.c utils/clean.c utils/parser.c garbage_collector/garbage_collector.c \
	libft/libft.a test/malloc_test.c
	$(CC) -g $^ -o $@

clean:
	$(RM) $(NAME)