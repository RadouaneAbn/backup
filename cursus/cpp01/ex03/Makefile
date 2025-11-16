CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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

# Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,
# hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp