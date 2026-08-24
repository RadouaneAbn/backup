CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXDEBUGFLAGS = -g3
SRCS = main.cpp PmergeMe.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = PmergeMe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)


re: fclean all

debug: fclean $(OBJS)
	$(CXX) $(CXXDEBUGFLAGS) $(OBJS) -o $(NAME)

.PHONY: all clean fclean re
