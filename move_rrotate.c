/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:21:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/06 09:36:24 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrotate(t_stack *stack)
{
	if (!stack->stack_elem)
		return ;
	stack->stack_elem = stack->stack_elem->prev;
}

void	rra(t_stack *stack, int print_move)
{
	ft_rrotate(stack);
	if (print_move)
		ft_putstr_fd("rra\n", STDOUT_FILENO);
}

void	rrb(t_stack *stack, int print_move)
{
	ft_rrotate(stack);
	if (print_move)
		ft_putstr_fd("rrb\n", STDOUT_FILENO);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print_move)
{
	ft_rrotate(stack_a);
	ft_rrotate(stack_b);
	if (print_move)
		ft_putstr_fd("rrr\n", STDOUT_FILENO);
}
