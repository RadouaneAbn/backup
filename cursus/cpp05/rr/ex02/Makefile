CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	Bureaucrat.cpp \
	AForm.cpp \
	ShrubberyCreationForm.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	tests/PresidentialPardonFormTests.cpp \
	tests/RobotomyRequestFormTests.cpp \
	tests/ShrubberyCreationFormTests.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) home_shrubbery

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	clear
	valgrind ./$(NAME)
	make fclean

.PHONY: all clean fclean re