SRC = main.c stack_actions.c sort_large_utils.c sort_large.c sort.c parsing.c move_swap.c error.c libft_utils_2.c \
      libft_utils.c move_push.c move_rotate.c move_rrotate.c

SRCS_DIR = ./src/

SRCS = $(addprefix $(SRCS_DIR), $(SRC))

OBJS	=  ${SRCS:.c=.o}

NAME = push_swap

all : ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -I ./include/ -c $< -o ${<:.c=.o}

${NAME} : $(OBJS)
	cc -Wall -Wextra -Werror -o ${NAME} $(OBJS)

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY:	all clean fclean re