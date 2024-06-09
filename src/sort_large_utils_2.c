/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:05:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/09 18:05:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_top_sb(t_stack *sb, t_stack_elem *cheap_e)
{
	while (sb->stack_elem != cheap_e)
	{
		if (cheap_e->position < sb->size / 2)
			rb(sb, 1);
		else
			rrb(sb, 1);
	}
}

void	ft_move_top_sa(t_stack *sa, t_stack_elem *cheap_e)
{
	while (sa->stack_elem != cheap_e->target_below_node)
	{
		if (cheap_e->target_below_node->position < sa->size / 2)
			ra(sa, 1);
		else
			rra(sa, 1);
	}
}

void	ft_get_min_on_top(t_stack *stack_a)
{
	t_stack_elem	*stack_min_value_elem;

	stack_min_value_elem = ft_min_elem(stack_a);
	while (stack_a->stack_elem != stack_min_value_elem)
	{
		if (stack_min_value_elem->position < stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}
