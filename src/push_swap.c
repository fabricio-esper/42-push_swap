/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/04 08:19:53 by fesper-s         ###   ########.fr       */
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
	char	**splitarg;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		validate_arg(argc, argv);
		if (argc == 2)
		{
			i = -1;
			splitarg = ft_split(argv[1], ' ');
			while (splitarg[++i])
				listadd_back(&stack_a, listnew(ft_atoi(splitarg[i])));
		}
		else
		{
			i = 0;
			while (++i < argc)
				listadd_back(&stack_a, listnew(ft_atoi(argv[i])));
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
