CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = AMateria.cpp Cure.cpp main.cpp Character.cpp Ice.cpp MateriaSource.cpp
OBJ = AMateria.o Cure.o main.o Character.o Ice.o MateriaSource.o

NAME = a.out

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean