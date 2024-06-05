/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:58:10 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/05 18:22:05 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int temp_elem_value;
	int second_elem;
	
	if (stack->size < 2)
		return ;
	temp_elem_value = stack->stack_elem->value;
	stack->stack_elem->value = stack->stack_elem->next->value;
	stack->stack_elem->next->value = temp_elem_value;
}
