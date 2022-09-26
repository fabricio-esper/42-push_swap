/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/26 11:22:39 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_decimal(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static void	validate_arg(int size, char **str)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (str[i][j])
		{
			if (!is_decimal(str[i][j]))
				error();
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		validate_arg(argc, argv);
	}
	else
		error();
	return (0);
}
