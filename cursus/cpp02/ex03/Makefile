CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGSX = -std=c++98

SRC = main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ = ${SRC:.cpp=.o}

TARGET = checkPoint

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(CFLAGSX) $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(TARGET)

.PHONY: all clean fclean