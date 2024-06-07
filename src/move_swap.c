/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 18:16:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	temp_elem_value;

	if (!stack->stack_elem)
		return ;
	if (stack->size < 2)
		return ;
	temp_elem_value = stack->stack_elem->value;
	stack->stack_elem->value = stack->stack_elem->next->value;
	stack->stack_elem->next->value = temp_elem_value;
}

void	sa(t_stack *stack, int print_move)
{
	ft_swap(stack);
	if (print_move)
		ft_putstr_fd("sa\n", STDOUT_FILENO);
}

void	sb(t_stack *stack, int print_move)
{
	ft_swap(stack);
	if (print_move)
		ft_putstr_fd("sb\n", STDOUT_FILENO);
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print_move)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	if (print_move)
		ft_putstr_fd("ss\n", STDOUT_FILENO);
}
