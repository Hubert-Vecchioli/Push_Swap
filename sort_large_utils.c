/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:50:34 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 00:30:28 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*ft_find_cheapest_elem(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*cheapest_to_move_b;
	t_stack_elem	*temp;
	int		i;

	i = 0;
	cheapest_to_move_b = stack_b->stack_elem;
	temp = stack_b->stack_elem;
	while (i < stack_b->size)
	{
		if (temp->move_cost < cheapest_to_move_b->move_cost) 
			cheapest_to_move_b = temp;
		if (cheapest_to_move_b->move_cost == 1)
			return (cheapest_to_move_b);
		temp = temp->next;
		i++;
	}
	return (cheapest_to_move_b);
}

t_stack_elem	*ft_min_elem(t_stack *stack_a)
{
	t_stack_elem *min_elem;

	min_elem = stack_a->stack_elem;
	while (min_elem->prev->value < min_elem->value)
		min_elem = min_elem->prev;
	return (min_elem);
}