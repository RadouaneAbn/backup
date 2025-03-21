CC := cc
CFALGS := -Wall -Wextra -Werror
RM := rm -rf
AR := ar rcs

SRC_FILES := ft_printf.c src/number_2.c src/more.c \
	src/ft_putchar.c src/printing_funcs.c \
	src/writer.c src/options.c src/print_all.c src/print_plus.c \
	src/converter.c src/calculate_width_precision.c

BONUS_FILES := ft_printf_bonus.c src_bonus/number_2_bonus.c src_bonus/more_bonus.c \
	src_bonus/ft_putchar_bonus.c src_bonus/printing_funcs_bonus.c \
	src_bonus/writer_bonus.c src_bonus/options_bonus.c src_bonus/print_all_bonus.c src_bonus/print_plus_bonus.c \
	src_bonus/converter_bonus.c src_bonus/calculate_width_precision_bonus.c

OBG_FILES := $(SRC_FILES:.c=.o)
BONUS_OBG_FILES := $(BONUS_FILES:.c=.o)
NAME := libftprintf.a

all: $(NAME)

$(NAME) : $(OBG_FILES)
	$(AR) $@ $^

bonus : $(BONUS_OBG_FILES)
	$(AR) $(NAME) $^

%.o: %.c
	$(CC) $(CFALGS) -c $< -o $@

clean:
	$(RM) $(OBG_FILES) $(BONUS_OBG_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean bonus
.SECONDARY: $(OBG_FILES) $(BONUS_OBG_FILES)