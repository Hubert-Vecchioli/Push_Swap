/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:08 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/06 09:37:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack *stack)
{
	if (!stack->stack_elem)
		return ;
	stack->stack_elem = stack->stack_elem->next;
}

void	ra(t_stack *stack, int print_move)
{
	ft_rotate(stack);
	if (print_move)
		ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack *stack, int print_move)
{
	ft_rotate(stack);
	if (print_move)
		ft_putstr_fd("rb\n", STDOUT_FILENO);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int print_move)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	if (print_move)
		ft_putstr_fd("rr\n", STDOUT_FILENO);
}
