/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:39:51 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/18 08:34:36 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_int_tab(t_stack **stack, int *i_buffer)
{
	int	i;
	int	buffer;

	i = 0;
	buffer = 0;
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
}

void	get_index(t_stack **stack, t_stack **s_buffer, int *i_buffer)
{
	int	i;

	i = 0;
	*s_buffer = *stack;
	while (i < listsize(*stack))
	{
		if (i_buffer[i] == (*s_buffer)->data)
		{
			(*s_buffer)->index = i;
			i++;
			*s_buffer = *stack;
		}
		else
			*s_buffer = (*s_buffer)->next;
	}
}

void	find_index(t_stack **stack)
{
	int		i;
	int		*i_buffer;
	t_stack	*s_buffer;

	i_buffer = malloc(sizeof(int) * (listsize(*stack)));
	if (!i_buffer)
		return ;
	i = 0;
	s_buffer = *stack;
	while (s_buffer)
	{
		i_buffer[i] = s_buffer->data;
		s_buffer = s_buffer->next;
		i++;
	}
	sort_int_tab(stack, i_buffer);
	get_index(stack, &s_buffer, i_buffer);
	free(i_buffer);
}
