# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 12:19:40 by fesper-s          #+#    #+#              #
#    Updated: 2022/10/03 09:05:14 by fesper-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CFLAGS	= -g -Wall -Werror -Wextra

LIBFT	= ./libft/libft.a

SRCS	= ./src/push_swap.c ./src/error.c ./src/utils.c ./src/utils2.c \
		  ./src/operations.c

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