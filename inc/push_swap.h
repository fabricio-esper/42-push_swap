/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:47:38 by fesper-s          #+#    #+#             */
/*   Updated: 2022/10/18 10:29:58 by fesper-s         ###   ########.fr       */
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

void	sort_three(t_stack **stack);
void	sort_five(int size, t_stack **stack_a, t_stack **stack_b);
void	sort_radix(int size, t_stack **stack_a, t_stack **stack_b);
void	sort(t_stack **stack_a, t_stack **stack_b);
void	error(void);
void	validate_arg(int size, char **str);
void	validate_dup(t_stack *stack);
int		a_is_sorted(t_stack *stack_a);
t_stack	*listnew(int data);
t_stack	*listadd(t_stack *stack);
t_stack	*listlast(t_stack *stack);
void	listadd_front(t_stack **stack, t_stack *new);
void	listadd_back(t_stack **stack, t_stack *new);
int		listsize(t_stack *stack);
void	stack_free(t_stack **stack);
void	add_split_in_stack(t_stack **stack, char *str);
void	add_argv_in_stack(t_stack **stack, int size, char **str);
void	sort_int_tab(t_stack **stack, int *i_buffer);
void	get_index(t_stack **stack, t_stack **s_buffer, int *i_buffer);
void	find_index(t_stack **stack);
void	swap_x(t_stack *stack, char c);
void	swap_s(t_stack *stack_a, t_stack *stack_b);
void	push_x(t_stack **stack_x, t_stack **stack_y, char c);
void	rotate_x(t_stack *stack, char c);
void	rotate_r(t_stack *stack_a, t_stack *stack_b);
void	rrotate_x(t_stack **stack, char c);
void	rrotate_r(t_stack **stack_a, t_stack **stack_b);

#endif