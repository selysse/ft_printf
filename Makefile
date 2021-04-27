NAME = libftprintf.a

SRC = ft_printf.c ft_atoi.c ft_itoa.c ft_print_parc.c ft_print_utils.c\
ft_printf_utils.c ft_print_char.c ft_print_str.c ft_print_ptr.c \
ft_print_int.c ft_print_unsigned.c ft_print_hex.c ft_print_precent.c \
			
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

%.o: %.c ft_printf.h
	gcc $(CFLAGS) -c $<

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all
