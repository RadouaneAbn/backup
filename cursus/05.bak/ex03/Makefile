CXX = c++
CXXFLAGS = -std=c++11 -Wall -Wextra -std=c++98

SRCS = ___
SRCS += main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = ___

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re