COMPIL = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft_pimped/include -Iinc

NAME = push_swap

SRCS_DIR = srcs/
SRCS_SRCS = $(addprefix ${SRCS_DIR}, check_input.c check_input_utils.c initialize.c main.c)

LIBFT_DIR = libft_pimped
LIBFT = ${LIBFT_DIR}/libft.a

${NAME}:
	${MAKE} -C ${LIBFT_DIR}
	${COMPIL} ${CFLAGS} ${SRCS_SRCS} ${LIBFT} -o ${NAME}

all: ${NAME}

clean:
	${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all

.PHONY: all clean fclean re


