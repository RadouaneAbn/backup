CC := cc
DEBUG := -g3
CFLAGS := -Wall -Wextra -Werror -pthread $(DEBUG)

SRC :=	ft_atoi.c \
		main.c \
		convert_args.c \
		init_simulation.c \
		init_table.c \	
		utils.c

MD_OBJ := $(SRC:.c=.o)

NAME := philo

$(NAME): $(MD_OBJ)
	cc $(MD_OBJ) -o $(NAME)

clean:
	rm -rf $(NAME)
	rm -rf $(MD_OBJ)