/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 13:50:34 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 18:54:41 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_elem	*ft_find_cheapest_elem(t_stack *stack_b)
{
	t_stack_elem	*cheapest_to_move_b;
	t_stack_elem	*temp;
	int				i;

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
	t_stack_elem	*min_elem;
	t_stack_elem	*temp_elem;
	int				i;

	min_elem = stack_a->stack_elem;
	temp_elem = stack_a->stack_elem;
	i = 0;
	while (i < stack_a->size)
	{
		if (min_elem->value > temp_elem->value)
			min_elem = temp_elem;
		temp_elem = temp_elem->next;
		i++;
	}
	ft_get_positions(stack_a);
	return (min_elem);
}

t_stack_elem	*ft_max_elem(t_stack *stack_a)
{
	t_stack_elem	*max_elem;
	t_stack_elem	*temp_elem;
	int				i;

	max_elem = stack_a->stack_elem;
	temp_elem = stack_a->stack_elem;
	i = 0;
	while (i < stack_a->size)
	{
		if (max_elem->value < temp_elem->value)
			max_elem = temp_elem;
		temp_elem = temp_elem->next;
		i++;
	}
	return (max_elem);
}

void	ft_set_extrema(t_stack *stack_a)
{
	stack_a->max_value = ft_max_elem(stack_a)->value;
	stack_a->min_value = ft_min_elem(stack_a)->value;
	stack_a->max_size = stack_a->size;
}

void	ft_best_move_back(t_stack *stack_a, t_stack *stack_b)
{
	ft_get_positions(stack_a);
	ft_get_positions(stack_b);
	ft_find_target_position(stack_a, stack_b);
	ft_determine_costs(stack_a, stack_b);
	ft_apply_cheapest_move(stack_a, stack_b);
}
