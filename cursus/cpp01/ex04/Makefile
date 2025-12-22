CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp
OBJ = ${SRC:.cpp=.o}

NAME = replace

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS)  $^ -o $@

clean:
				rm -rf $(OBJ)

fclean: clean
				rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean