/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:48:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/06 14:21:16 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// print_stack for testing
void	print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_printf("index = %d, %d\n", stack->index, stack->data);
		stack = stack->next;
	}
}

void	get_index(t_stack **stack)
{
	int		i;
	int		buffer;
	int		*i_buffer;
	t_stack	*s_buffer;

	i_buffer = malloc(sizeof(int) * (listsize(*stack)));
	i = 0;
	s_buffer = *stack;
	while (s_buffer)
	{
		i_buffer[i] = s_buffer->data;
		s_buffer = s_buffer->next;
		i++;
	}
	i = 0;
	while (i < listsize(*stack) - 1)
	{
		if (i_buffer[i] > i_buffer[i + 1])
		{
			buffer = i_buffer[i];
			i_buffer[i] = i_buffer[i + 1];
			i_buffer[i + 1] = buffer;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
	s_buffer = *stack;
	while (i < listsize(*stack))
	{
		if (i_buffer[i] == s_buffer->data)
		{
			s_buffer->index = i;
			i++;
			s_buffer = *stack;
		}
		else
			s_buffer = s_buffer->next;
	}
	free(i_buffer);
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
		get_index(&stack_a);
		// testing
		print_stack(stack_a);
		stack_free(&stack_a);
		stack_free(&stack_b);
	}
	return (0);
}
