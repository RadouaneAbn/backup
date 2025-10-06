CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

SRC = $(wildcard *.cpp)
OBJ = ${SRC:.cpp=.o}

TARGET = phonebook

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

.PHONY: all clean fclean