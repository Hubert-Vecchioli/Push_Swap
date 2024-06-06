/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 10:46:09 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/06 11:20:38 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_large(t_stack *stack_a, t_stack *stack_b)
{
	t_cheapest_move *cheapest_move; 

	while (stack_a->size > 3)
		pb(stack_a, stack_b, 1);
	ft_sort_three_elem(stack_a);
	
	while (stack_b->size)
	{
		ft_cheapest_move(stack_a, stack_b, cheapest_move);
		ft_apply_cheapest_move(stack_a, stack_b, ccheapest_move);
	}
}

void ft_cheapest_move(t_stack *stack_a, t_stack *stack_b, t_cheapest_move *cheapest_move)
{
	int	i;
	t_cheapest_move *temp;
	t_cheapest_move *min;

	min->nb_moves_needed = ft_min_4(method_1,method_2,method_3,method_4)
	min->index = stack_b->size - i
	i = -1;
	while (stack_b->size - ++i)
	{
		temp->nb_moves_needed = ft_min_4(method_1,method_2,method_3,method_4)
		temp->index = stack_b->size - i
		if (temp->nb_moves_needed < min->nb_moves_needed)
		{
			min->index = temp->index
			min->nb_moves_needed = temp->nb_moves_needed
		}
	}
	cheapest_move->index = min->index
	cheapest_move->nb_moves_needed = min->nb_moves_needed
}

void ft_apply_cheapest_move(t_stack *stack_a, t_stack *stack_b, t_cheapest_move cheapest_move)
{
	if (method_1 == cheapest_move->nb_moves_needed)
		method_1
	else if (method_2 == cheapest_move->nb_moves_needed)
		method_2
	else if (method_3 == cheapest_move->nb_moves_needed)
		method_3
	else if (method_4 == cheapest_move->nb_moves_needed)
		method_4
}

int	ft_min_4(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return a;
	if (b <= a && b <= c && b <= d)
		return b;
	if (c <= b && c <= a && c <= d)
		return c;
	if (d <= b && d <= c && d <= a)
		return d;
}
