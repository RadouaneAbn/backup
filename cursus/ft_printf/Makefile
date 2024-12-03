CC := cc
CFALGS := -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

SRC_FILES := ft_printf.c src/number_2.c src/more.c \
	src/ft_putchar.c src/printing_funcs.c src/error_handle.c \
	src/writer.c src/options.c src/print_all.c src/print_plus.c
	src/converter.c src/calculate_width_precision.c
OBG_FILES := $(SRC_FILES:.c=.o)
NAME := libftprintf.a

all: $(NAME)

$(NAME) : $(OBG_FILES)
	$(AR) $@ $^

bonus : $(OBG_FILES)
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