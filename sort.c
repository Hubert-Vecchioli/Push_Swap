/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:24:29 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/06 13:49:54 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack_elem *head;
	
	head = stack_a->stack_elem;
	if (!head || !*head)
		return (0);
	while (head->next != stack_a->stack_elem)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next 
	}
	return (1);
}

void ft_sort_three_elem(t_stack *stack_a)
{
	int	first_elem;
	int	second_elem;
	int	third_elem;
	
	first_elem = stack_a->stack_elem->value
	second_elem = stack_a->stack_elem->next->value
	third_elem = stack_a->stack_elem->prev->value
	if (first_elem < second_elem && second_elem < third_elem)// 123
		return ;
	else if (first_elem < third_elem && second_elem > third_elem)// 132
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first_elem > second_elem && first_elem < third_elem)// 213
		sa(stack_a, 1);
	else if (first_elem < second_elem && first_elem > third_elem)// 231
		rra(stack_a, 1);
	else if (third_elem > second_elem && third_elem < first_elem)// 312
		ra(stack_a, 1);
	else if (third_elem < second_elem && second_elem < first_elem)// 321
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
}

void ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 1)
	else if (stack_a->size == 2)
		sa(stack_a, 1);
	else if (stack_a->size == 3)
		ft_sort_three_elem(stack_a);
	else if (stack_a->size > 3)
		ft_sort_large(stack_a, stack_b);
}