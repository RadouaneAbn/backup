CC = cc -pthread
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = convert_args.c ft_atoi.c ft_memset.c ft_usleep.c init_simulation.c \
	main.c monitor.c philo_utils.c print_functions.c routine.c utils.c
OBJ_FILES = $(SRC_FILES:%.c=%.o)

INCLUDE = .

TARGET = philo

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I $(INCLUDE)

clean:
	@rm -rf $(OBJ_FILES)

fclean: clean
	@rm -rf $(TARGET)

re: fclean all

.PHONY : all clean fclean re