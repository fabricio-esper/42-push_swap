/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/18 10:28:24 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	while (!a_is_sorted(*stack))
	{
		if ((*stack)->index > (*stack)->next->index)
			swap_x(*stack, 'a');
		else
			rrotate_x(stack, 'a');
	}
}

void	sort_five(int size, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = -1;
	while (++i < 2)
	{
		while ((*stack_a)->index != 0 && (*stack_a)->index != size - 1)
			rotate_x(*stack_a, 'a');
		push_x(stack_b, stack_a, 'b');
	}
	sort_three(stack_a);
	i = -1;
	while (++i < 2)
	{
		push_x(stack_a, stack_b, 'a');
		if ((*stack_a)->index > (*stack_a)->next->index)
			rotate_x(*stack_a, 'a');
	}
}

void	sort_radix(int size, t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;

	j = 0;
	while (!a_is_sorted(*stack_a))
	{
		i = -1;
		while (++i < size)
		{
			if (((*stack_a)->index >> j & 1) == 1)
				rotate_x(*stack_a, 'a');
			else
				push_x(stack_b, stack_a, 'b');
		}
		while (listsize(*stack_b) != 0)
			push_x(stack_a, stack_b, 'a');
		j++;
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = listsize(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(size, stack_a, stack_b);
	else
		sort_radix(size, stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		validate_arg(argc, argv);
		if (argc == 2)
			add_split_in_stack(&stack_a, argv[1]);
		else
			add_argv_in_stack(&stack_a, argc, argv);
		validate_dup(stack_a);
		if (a_is_sorted(stack_a))
			return (0);
		find_index(&stack_a);
		sort(&stack_a, &stack_b);
		stack_free(&stack_a);
		stack_free(&stack_b);
	}
	return (0);
}
