/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:09 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 09:23:04 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem *stack_min_value_elem; 

	while (stack_a->size > 3)
		pb(stack_a, stack_b, 1);
	ft_sort_three_elem(stack_a);
	
	while (stack_b->size)
	{
		ft_get_positions(stack_a);
		ft_get_positions(stack_b);
		ft_find_target_position(stack_a, stack_b);
		ft_determine_costs(stack_a, stack_b);
		ft_apply_cheapest_move(stack_a, stack_b);
	}
	stack_min_value_elem = ft_min_elem(stack_a);
	while (stack_a->stack_elem != stack_min_value_elem)
		if (stack_min_value_elem->position < stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
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
	t_stack_elem	*head_b;
	t_stack_elem	*head_a;
	int				i;
	int				j;

	head_b = stack_b->stack_elem;
	i = 0;
	while (i < stack_b->size)
	{
		head_a = stack_a->stack_elem;
		j = 0;
		while (j < stack_a->size)
		{
			if (head_a->value < head_b->value && head_a->next->value > head_b->value)
				head_b->target_to_go_below_node = head_a->next;
			if (head_a->value < head_b->value && head_a->next->value < head_b->value
				 && head_a->value > head_a->next->value)
				head_b->target_to_go_below_node = head_a->next;
			if (head_a->value > head_b->value && head_a->next->value > head_b->value
				 && head_a->value > head_a->next->value)
				head_b->target_to_go_below_node = head_a->next;
			head_a=head_a->next;
			j++;
		}
		head_b = head_b->next;
		i++;
	}
}

void	ft_determine_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem	*head_b;
	int		i;

	head_b = stack_b->stack_elem;
	i = 0;
	while (i < stack_b->size)
	{
		if (head_b->position < stack_b->size / 2)
			head_b->move_cost = head_b->position;
		else
			head_b->move_cost = stack_b->size - (head_b->position);
		if (head_b->target_to_go_below_node->position < stack_a->size / 2)
			head_b->move_cost += head_b->target_to_go_below_node->position;
		else
			head_b->move_cost += stack_a->size - (head_b->target_to_go_below_node->position);
		head_b = head_b->next;
		i++;
	}
}

void	ft_apply_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	t_stack_elem *cheapest_elem;
	
	cheapest_elem = ft_find_cheapest_elem(stack_b);
	if (cheapest_elem->position < stack_b->size / 2 && 
		cheapest_elem->target_to_go_below_node->position < stack_a->size / 2)
		while (stack_a->stack_elem != cheapest_elem->target_to_go_below_node
			&& stack_b->stack_elem != cheapest_elem)
			rr(stack_a, stack_b, 1);
	if (cheapest_elem->position >= stack_b->size / 2 && 
		cheapest_elem->target_to_go_below_node->position >= stack_a->size / 2)
		while (stack_a->stack_elem != cheapest_elem->target_to_go_below_node
			&& stack_b->stack_elem != cheapest_elem)
			rrr(stack_a, stack_b, 1);
	while (stack_a->stack_elem != cheapest_elem->target_to_go_below_node)
		if (cheapest_elem->target_to_go_below_node->position < stack_a->size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
	while (stack_b->stack_elem != cheapest_elem)
		if (cheapest_elem->position < stack_b->size / 2)
			rb(stack_b, 1);
		else
			rrb(stack_b, 1);
	pa(stack_a, stack_b, 1);
}
