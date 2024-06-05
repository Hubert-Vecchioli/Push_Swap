/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:24:29 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/05 11:31:25 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack_elem *head;
	
	head = (*stack_a).stack_elem;
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
	
	if (first_elem > second_elem && second_elem > third_elem)
	// do nothing
	else if (first_elem > third_elem && third_elem > second_elem)
	else if (second_elem > first_elem && first_elem > third_elem)
	else if (third_elem > second_elem && second_elem > first_elem)
	else if (third_elem > first_elem && first_elem > second_elem)
	else if (second_elem > third_elem && third_elem > first_elem)
}

void ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	// cas 1 elem
	// cas 2 elems --> rotation meme pile car non sort
	// cas 3 elements
	// cas 3+ elements
}