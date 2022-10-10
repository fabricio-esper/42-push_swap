/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:51:55 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/10 13:12:57 by fesper-s         ###   ########.fr       */
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
	t_stack	*buffer;
	int		i_buffer;

	buffer = stack;
	while (stack->next)
	{
		i_buffer = stack->data;
		while (stack->next)
		{
			stack = stack->next;
			if (i_buffer == stack->data)
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

int	a_is_sorted(t_stack *stack_a)
{
	while (stack_a->next)
	{
		if (stack_a->data > stack_a->next->data)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}
