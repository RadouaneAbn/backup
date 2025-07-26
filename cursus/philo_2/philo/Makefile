CC = cc -pthread #-g3 -fsanitize=thread
CFLAGS = -Wall -Wextra -Werror

SRC_FILES = $(wildcard *.c)
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

run: $(TARGET)
	clear
	make clean
	./$(TARGET) 3 180 60 60

val: $(TARGET)
	clear
	make clean
	valgrind -s --leak-check=full --show-leak-kinds=all ./$(TARGET) 3 180 60 60

re: fclean all
