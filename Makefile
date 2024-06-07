SRC 			= main.c stack_actions.c sort_large_utils.c sort_large.c sort.c parsing.c move_swap.c error.c libft_utils_2.c \
    			  libft_utils.c move_push.c move_rotate.c move_rrotate.c sort_large_utils_2.c
SRCS_DIR 		= ./src/
SRCS 			= $(addprefix $(SRCS_DIR), $(SRC))

OBJS			=  ${SRCS:.c=.o}

CHECKER_SRC		= checker.c get_next_line.c get_next_line_utils.c
CHECKER_DIR		= ./checker/
CHECKER			= $(addprefix $(CHECKER_DIR), $(CHECKER_SRC))
CHECKER_OBJS	=  ${CHECKER:.c=.o}
NAME_CHECKER	= ./checker/checker

NAME = push_swap

all : ${NAME}

.c.o:
	cc -Wall -Wextra -Werror -I ./include/ -c $< -o ${<:.c=.o}

${NAME} : $(OBJS)
	cc -Wall -Wextra -Werror -o ${NAME} $(OBJS)

checker: $(OBJS) $(CHECKER_OBJS)
	cc -Wall -Wextra -Werror -I ./include/ $(OBJS) $(CHECKER_OBJS) -o $(NAME_CHECKER)

clean :
	rm -f ${OBJS} $(CHECKER_OBJS)

fclean : clean
	rm -f ${NAME} $(NAME_CHECKER)

re : fclean all

.PHONY:	all clean fclean re