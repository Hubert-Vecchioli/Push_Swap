/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 05:24:29 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/04 05:42:34 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack_a)
{
	t_stack_elem *head;
	
	head = (*stack_a).stack_elem;
	if (!head || !*head)
		return (0);
	while ((*head).next != (*stack_a).stack_elem)
	{
		if ((*head).value > (*(*head).next).value)
			return (0);
		head = (*head).next;
	}
	return (1);
}

void ft_sort(t_stack *stack_a, t_stack *stack_b)
{
	// cas 3 elements
	// cas 3+ elements
}