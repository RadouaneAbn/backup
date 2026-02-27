CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = identify.cpp main.cpp
OBJ = identify.o main.o

NAME = identity

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean