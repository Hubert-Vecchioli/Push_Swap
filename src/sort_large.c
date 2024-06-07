/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:09 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 19:11:27 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*stack_min_value_elem;

	ft_set_extrema(stack_a);
	while (stack_a->size > 3)
	{
		if (stack_a->size > stack_a->max_size / 2
			&& stack_a->stack_elem->value < (stack_a->max_value
				- stack_a->min_value) / 2)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
	}
	ft_sort_three_elem(stack_a);
	while (stack_b->size)
	{
		ft_best_move_back(stack_a, stack_b);
	}
	stack_min_value_elem = ft_min_elem(stack_a);
	while (stack_a->stack_elem != stack_min_value_elem)
	{
		if (stack_min_value_elem->position < stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	}
}

void	ft_get_positions(t_stack *stack)
{
	t_stack_elem	*head;
	int				i;

	if (!stack || !stack->stack_elem)
		return ;
	i = 0;
	head = stack->stack_elem;
	while (stack->size > i)
	{
		head->position = i;
		head = head->next;
		i++;
	}
}

void	ft_find_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*hb;
	t_stack_elem	*ha;
	int				i;
	int				j;

	hb = stack_b->stack_elem;
	i = -1;
	while (++i < stack_b->size)
	{
		ha = stack_a->stack_elem;
		j = -1;
		while (++j < stack_a->size)
		{
			if (ha->value < hb->value && ha->next->value > hb->value)
				hb->target_below_node = ha->next;
			if (ha->value < hb->value && ha->next->value < hb->value
				&& ha->value > ha->next->value)
				hb->target_below_node = ha->next;
			if (ha->value > hb->value && ha->next->value > hb->value
				&& ha->value > ha->next->value)
				hb->target_below_node = ha->next;
			ha = ha->next;
		}
		hb = hb->next;
	}
}

void	ft_determine_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*head_b;
	int				i;

	head_b = stack_b->stack_elem;
	i = 0;
	while (i < stack_b->size)
	{
		if (head_b->position < stack_b->size / 2)
			head_b->move_cost = head_b->position;
		else
			head_b->move_cost = stack_b->size - (head_b->position);
		if (head_b->target_below_node->position < stack_a->size / 2)
			head_b->move_cost += head_b->target_below_node->position;
		else
			head_b->move_cost += stack_a->size
				- (head_b->target_below_node->position);
		head_b = head_b->next;
		i++;
	}
}

void	ft_apply_cheapest_move(t_stack *sa, t_stack *sb)
{
	t_stack_elem	*cheap_e;

	cheap_e = ft_find_cheapest_elem(sb);
	if (cheap_e->position < sb->size / 2
		&& cheap_e->target_below_node->position < sa->size / 2)
	{
		while (sa->stack_elem != cheap_e->target_below_node
			&& sb->stack_elem != cheap_e)
			rr(sa, sb, 1);
	}
	if (cheap_e->position >= sb->size / 2
		&& cheap_e->target_below_node->position >= sa->size / 2)
	{
		while (sa->stack_elem != cheap_e->target_below_node
			&& sb->stack_elem != cheap_e)
			rrr(sa, sb, 1);
	}
	ft_move_top_sb(sb, cheap_e);
	ft_move_top_sa(sa, cheap_e);
	pa(sa, sb, 1);
}
