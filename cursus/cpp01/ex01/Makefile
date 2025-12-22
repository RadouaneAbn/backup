CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = zombieHorde.cpp Zombie.cpp main.cpp
OBJ = zombieHorde.o Zombie.o main.o

NAME = zombieHord

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean