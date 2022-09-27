/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/27 10:31:21 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	int	i;

	if (argc > 1)
	{
		validate_arg(argc, argv);
		i = 1;
		while (i < argc)
		{
			listadd_back(&stack_a, listnew(ft_atoi(argv[i])));
			ft_printf("%d\n", stack_a->data);
			stack_a = stack_a->next;
			i++;
		}
	}
	else
		error();
	return (0);
}
