/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:55 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/04 08:36:39 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_decimal(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	validate_arg(int size, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ')
				j++;
			if (str[i][j] == '-')
				j++;
			if (!ft_isdigit(str[i][j]))
				error();
			j++;
		}
		i++;
	}
}

void	validate_dup(t_stack *stack)
{
	void	*buffer;
	int		buffer2;
	
	buffer = stack;
	while (stack->next)
	{
		buffer2 = stack->data;
		while (stack->next)
		{
			stack = stack->next;
			if (buffer2 == stack->data)
				error();
		}
		stack = buffer;
		if (stack->next != 0)
		{
			stack = stack->next;
			buffer = stack;
		}
	}
}
