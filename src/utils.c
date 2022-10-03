/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 08:33:13 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/03 11:06:35 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*listnew(int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	return (new);
}

t_stack	*listlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

void	listadd_front(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

void	listadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*buffer;

	if (!stack)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	buffer = listlast(*stack);
	buffer->next = new;
}
