CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC =  tests.cpp Account.cpp 
OBJ = tests.o Account.o 

NAME = Bank

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean