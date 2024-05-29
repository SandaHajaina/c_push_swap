SRC = algorithm.c algorithm_utils.c check_error.c check_sorted.c execute_move.c \
		find_min_max.c free_stack.c ft_atoi.c ft_split.c operations.c \
		push_operations.c push_swap.c reverse_operations.c rotate_operations.c \
		sort_three.c string_utils.c swap_operations.c utils_2.c utils.c

OBJ = ${SRC:.c=.o}

NAME = push_swap

CC = gcc

CFLAGS = -Werror -Wextra -Wall

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all : ${NAME}

clean :
			rm -f ${OBJ}

fclean : clean
			rm -f ${NAME}

re : fclean all

.PHONY: all clean fclean re