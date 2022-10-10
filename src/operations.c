/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:14:38 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/10 13:59:31 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_x(t_stack *stack)
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
}

void	push_x(t_stack **stack_x, t_stack **stack_y)
{
	t_stack	*buffer;

	listadd_front(stack_x, listnew((*stack_y)->data));
	(*stack_x)->index = (*stack_y)->index;
	buffer = *stack_y;
	*stack_y = (*stack_y)->next;
	free(buffer);
}

void	rotate_x(t_stack *stack)
{
	int	buffer;
	int	index;

	index = stack->index;
	buffer = stack->data;
	while (stack->next)
	{
		stack->data = stack->next->data;
		stack = stack->next;
	}
	stack->data = buffer;
}

void	rrotate_x(t_stack **stack)
{
	t_stack	*buffer;
	t_stack	*init;

	buffer = listlast(*stack);
	listadd_front(stack, listnew(buffer->data));
	init = *stack;
	while ((*stack)->next != buffer)
		*stack = (*stack)->next;
	(*stack)->next = 0;
	*stack = init;
	free(buffer);
}
