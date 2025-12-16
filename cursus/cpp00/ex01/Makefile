CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g


SRC = main.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJ = main.o Contact.o PhoneBook.o utils.o

NAME = phonebook

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean