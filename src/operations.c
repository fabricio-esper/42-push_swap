/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:14:38 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/11 08:59:00 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_x(t_stack *stack, char c)
{
	int	buffer;
	int	index;

	index = stack->index;
	buffer = stack->data;
	stack->index = stack->next->index;
	stack->data = stack->next->data;
	stack = stack->next;
	stack->index = index;
	stack->data = buffer;
	if (c == 'a')
		ft_printf("sa\n");
	else if (c == 'b')
		ft_printf("sb\n");
	else
		ft_printf("s");
}

void	swap_s(t_stack *stack_a, t_stack *stack_b)
{
	swap_x(stack_a, 's');
	swap_x(stack_b, 's');
	ft_printf("\n");
}

void	push_x(t_stack **stack_x, t_stack **stack_y, char c)
{
	t_stack	*buffer;

	listadd_front(stack_x, listnew((*stack_y)->data));
	(*stack_x)->index = (*stack_y)->index;
	buffer = *stack_y;
	*stack_y = (*stack_y)->next;
	free(buffer);
	ft_printf("p%c\n", c);
}

void	rotate_x(t_stack *stack, char c)
{
	int	buffer;
	int	index;

	index = stack->index;
	buffer = stack->data;
	while (stack->next)
	{
		stack->index = stack->next->index;
		stack->data = stack->next->data;
		stack = stack->next;
	}
	stack->index = index;
	stack->data = buffer;
	if (c == 'a')
		ft_printf("ra\n");
	else if (c == 'b')
		ft_printf("rb\n");
	else
		ft_printf("r");
}

void	rotate_r(t_stack *stack_a, t_stack *stack_b)
{
	rotate_x(stack_a, 'r');
	rotate_x(stack_b, 'r');
	ft_printf("\n");
}
