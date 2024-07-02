NAME = libftprintf.a

CC = gcc 

CFLAGS = -Wall -Wextra -Werror -I.

SRC = ft_printf.c print_diu.c print_x.c

OBJ = ${SRC:.c=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${MAKE} -C libft
	cp libft/libft.a ./
	mv libft.a ${NAME}
	ar rc ${NAME} ${OBJ}
	ranlib ${NAME}

%.o: %.c ft_printf.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${MAKE} -C libft clean
	rm -rf ${OBJ}

fclean: clean
	${MAKE} -C libft fclean
	rm -rf ${NAME}
	rm -rf libft.a

re: fclean all

.PHONY: all clean fclean re
