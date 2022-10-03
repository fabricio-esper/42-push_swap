/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 08:57:12 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/03 16:08:27 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	listsize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	stack_free(t_stack **stack)
{
	t_stack *buffer;
	t_stack *del;
	
	buffer = *stack;
	ft_printf("stack free inicio\n");
	while (buffer)
	{
		del = buffer;
		ft_printf("%d\n", buffer->data);
		buffer = buffer->next;
		free(del);
	}
	ft_printf("stack free final\n");
	*stack = NULL;
}
