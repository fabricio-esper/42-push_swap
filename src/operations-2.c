/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations-2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 08:58:44 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/17 08:40:31 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate_x(t_stack **stack, char c)
{
	t_stack	*buffer;
	t_stack	*init;

	buffer = listlast(*stack);
	listadd_front(stack, listnew(buffer->data));
	(*stack)->index = buffer->index;
	init = *stack;
	while ((*stack)->next != buffer)
		*stack = (*stack)->next;
	(*stack)->next = 0;
	*stack = init;
	free(buffer);
	if (c == 'a')
		ft_printf("rra\n");
	else if (c == 'b')
		ft_printf("rrb\n");
	else
		ft_printf("r");
}

void	rrotate_r(t_stack **stack_a, t_stack **stack_b)
{
	rrotate_x(stack_a, 'r');
	rrotate_x(stack_b, 'r');
	ft_printf("r\n");
}
