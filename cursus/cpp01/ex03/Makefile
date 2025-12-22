CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
OBJ = main.o HumanA.o HumanB.o Weapon.o

NAME = string

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $^ -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean

# Makefile, main.cpp, Weapon.{h, hpp}, Weapon.cpp, HumanA.{h,
# hpp}, HumanA.cpp, HumanB.{h, hpp}, HumanB.cpp