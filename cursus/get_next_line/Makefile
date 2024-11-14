CC := cc
CFLAGS := -Wall -Wextra -Werror
SRC := get_next_line_utils.c \
	get_next_line.c
MAIN := main.c
NAME := a.out
RM := rm -rf
OBJ := $(SRC:.c=.o) $(MAIN:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: clean all
