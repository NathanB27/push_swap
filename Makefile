COMPIL = cc
CFLAGS = -Wall -Werror -Wextra -Ilibft_pimped/include -Iinc

NAME = push_swap
NAME_BONUS = checker_bonus

SRCS_DIR = srcs/
SRCS_SRCS = $(addprefix ${SRCS_DIR}, check_input.c check_input_utils.c check_stack.c initialize.c initialize_utils.c \
			movement/rotate.c movement/reverse_rotate.c movement/swap.c algo_sort.c movement/push.c main.c find_cost.c sort.c position.c \
			target_node.c function_free.c find_min_max.c cheapest.c)

SRCS_DIR_BONUS = bonus/
SRCS_SRCS_BONUS = $(bonus/checker.c bonus/utils.c movement/rotate.c movement/reverse_rotate.c movement/push.c movement/swap.c)

LIBFT_DIR = libft_pimped
LIBFT = ${LIBFT_DIR}/libft.a
LIBFT_AR = $(addprefix ${LIBFT_DIR}, ${LIBFT_NAME})

${NAME}:
	${MAKE} -C ${LIBFT_DIR}
	${COMPIL} ${CFLAGS} ${SRCS_SRCS} ${LIBFT} -o ${NAME}


${NAME_BONUS}:
	${MAKE} -C ${LIBFT_DIR}	
	${COMPIL} ${CFLAGS} ${SRCS_SRCS_BONUS} ${SRCS_SRCS} ${LIBFT} -o ${NAME_BONUS}

all: ${NAME}

bonus: ${NAME_BONUS}

clean:
	${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	rm -f ${NAME} ${NAME_BONUS}
	${MAKE} -C ${LIBFT_DIR} fclean

re: fclean all 

.PHONY: all clean fclean re


