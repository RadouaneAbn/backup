CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

TARGET = string

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean