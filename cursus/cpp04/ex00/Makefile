CXX = c++
CXXFLAGS = -Wall -Wextra -Werror

SRC = Animal.cpp WrongAnimal.cpp Dog.cpp Cat.cpp main.cpp
OBJ = Animal.o WrongAnimal.o Dog.o Cat.o main.o

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