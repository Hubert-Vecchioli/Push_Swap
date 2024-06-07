/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 19:05:26 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 19:10:34 by hvecchio         ###   ########.fr       */
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
