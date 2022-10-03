/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/03 16:09:56 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("%d\n", stack->data);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
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
		// testing
		print_stack(stack_a);
		stack_free(&stack_a);
		stack_free(&stack_b);
	}
	else
		error();
	return (0);
}
