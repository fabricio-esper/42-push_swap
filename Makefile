NAME	= push_swap

CFLAGS	= -g -Wall -Werror -Wextra

SRCS	= ./src/push_swap.c

OBJS	= $(SRCS:.c=.o)

$(NAME):	$(OBJS)
			make -C ./libft
			cc $^ $(CFLAGS) $(LIBFT) -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f (NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re