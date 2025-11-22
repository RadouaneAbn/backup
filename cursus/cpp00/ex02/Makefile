CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

SRC =  tests.cpp Account.cpp 
OBJ = ${SRC:.cpp=.o}

TARGET = Bank

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(TARGET)

.PHONY: all clean fclean