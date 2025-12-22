CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

TARGET = DiamondTrap
SRC = main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp

OBJ = ${SRC:.cpp=.o}

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

re: fclean all

run: re
	clear
	./$(TARGET)

.PHONY: all clean fclean