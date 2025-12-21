CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = Animal.cpp WrongAnimal.cpp WrongCat.cpp Dog.cpp Cat.cpp main.cpp
OBJ = Animal.o WrongAnimal.o WrongCat.o Dog.o Cat.o main.o

NAME = animal

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean