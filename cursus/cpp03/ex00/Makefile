CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

TARGET = ClapTrap
SRC = main.cpp ClapTrap.cpp

OBJ = ${SRC:.cpp=.o}

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

.PHONY: all clean fclean