CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

# UTILS := src/pipex_utils.c
# SRC := src/pipex.c

# OBJ_FILES := $(UTILS:.c=.o) $(SRC:.c=.o)

NAME := pipex

all: $(NAME)

$(NAME): src/pipex.c utils/clean.c libft/libft.a
	$(CC) -g $^ -o $@

clean:
	$(RM) $(NAME)