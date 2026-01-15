CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g

SRC = Data.cpp Serializer.cpp main.cpp
OBJ = Data.o Serializer.o main.o

NAME = serializer

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean