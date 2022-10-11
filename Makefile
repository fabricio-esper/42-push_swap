# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 12:19:40 by fesper-s          #+#    #+#              #
#    Updated: 2022/10/11 08:59:39 by fesper-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -g -Wall -Werror -Wextra

LIBFT	= ./libft/libft.a

SRCS	= ./src/main.c ./src/error.c ./src/utils.c ./src/list-utils.c \
		  ./src/operations.c ./src/operations-2.c ./src/index.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			cc $(CFLAGS) -c $< -o $(<:.c=.o) -I ./inc

$(NAME):	$(OBJS)
			make -C ./libft && make bonus -C ./libft
			cc $^ $(CFLAGS) $(LIBFT) -o $@

all:		$(NAME)

clean:
			rm -f $(OBJS)
			make clean -C ./libft

fclean:		clean
			rm -f $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re