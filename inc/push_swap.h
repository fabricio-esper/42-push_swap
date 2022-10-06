/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:47:38 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/06 12:01:20 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}					t_stack;

// error.c
void	error(void);
void	validate_arg(int size, char **str);
void	validate_dup(t_stack *stack);
int		a_is_sorted(t_stack *stack_a);
// list-utils.c
t_stack	*listnew(int data);
t_stack	*listadd(t_stack *stack);
t_stack	*listlast(t_stack *stack);
void	listadd_front(t_stack **stack, t_stack *new);
void	listadd_back(t_stack **stack, t_stack *new);
// utils.c
int		listsize(t_stack *stack);
void	stack_free(t_stack **stack);
void	add_split_in_stack(t_stack **stack, char *str);
void	add_argv_in_stack(t_stack **stack, int size, char **str);
// operations.c
void	swap_x(t_stack *stack);
void	push_x(t_stack **stack_x, t_stack **stack_y);
void	rotate_x(t_stack *stack);
void	rrotate_x(t_stack **stack);
// push_swap.c


#endif