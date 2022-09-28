/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/09/28 14:09:26 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc > 1)
	{
		validate_arg(argc, argv);
		i = 1;
		while (i < argc)
		{
			listadd_back(&stack_a, listnew(ft_atoi(argv[i])));
			i++;
		}
		validate_dup(stack_a);
		// testing rotate_x operation
		stack_b = NULL;
		rrotate_x(stack_a);
		i = 2;
		while (i--)
		{
			ft_printf("%d\n", stack_a->data);
			stack_a = stack_a->next;
		}
	}
	else
		error();
	return (0);
}
