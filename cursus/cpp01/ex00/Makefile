CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJ = Zombie.o newZombie.o randomChump.o main.o

NAME = zombie

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean