CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = main.cpp RPN.cpp
OBJ = main.o RPN.o

NAME = RPN

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean