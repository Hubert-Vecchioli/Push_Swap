/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:05 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 18:15:52 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack *stack_src, t_stack *stack_dest)
{
	t_stack_elem	*temp_elem;

	temp_elem = stack_src->stack_elem;
	if (!stack_src->stack_elem)
		return ;
	if (stack_src->size == 1)
	{
		stack_src->stack_elem = NULL;
	}
	else
	{
		stack_src->stack_elem->prev->next = stack_src->stack_elem->next;
		stack_src->stack_elem->next->prev = stack_src->stack_elem->prev;
		stack_src->stack_elem = stack_src->stack_elem->next;
	}
	stack_src->size -= 1;
	ft_add_back(stack_dest, temp_elem);
	ft_rrotate(stack_dest);
}

void	pa(t_stack *stack_a, t_stack *stack_b, int print_move)
{
	ft_push(stack_b, stack_a);
	if (print_move)
		ft_putstr_fd("pa\n", STDOUT_FILENO);
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print_move)
{
	ft_push(stack_a, stack_b);
	if (print_move)
		ft_putstr_fd("pb\n", STDOUT_FILENO);
}
