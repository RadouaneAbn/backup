CC := cc
CFALGS := -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

SRC_FILES := ft_printf.c number.c
OBG_FILES := $(SRC_FILES:.c=.o)
NAME := libftprintf.a

all: $(NAME)

$(NAME) : $(OBG_FILES)
	$(AR) $@ $^

%.o: %.c
	$(CC) $(CFALGS) -c $< -o $@

clean:
	$(RM) $(OBG_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean
.SECONDARY: $(OBG_FILES)