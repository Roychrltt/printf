NAME = libftprintf.a

CC = gcc -Wall -Wextra -Werror -I.

SRC = ft_printf.c print_diu.c print_p.c print_x.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	make all -C libft
	cp libft/libft.a ./libft.a
	mv libft.a ${NAME}
	ar rc ${NAME} ${OBJ}

%.o: %.c ft_printf.h
	${CC} -c $< -o $@

clean:
	make clean -C libft
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}
	rm -rf libft/libft.a

re: fclean all

.PHONY: all clean fclean re
