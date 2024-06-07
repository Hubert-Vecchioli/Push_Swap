/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:30:20 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 18:28:26 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_add_back(t_stack *stack, t_stack_elem *new_elem)
{
	if (!stack->stack_elem)
	{
		stack->stack_elem = new_elem;
		stack->stack_elem->next = new_elem;
		stack->stack_elem->prev = new_elem;
	}
	else
	{
		ft_elem_last(stack->stack_elem)->next = new_elem;
		new_elem->prev = ft_elem_last(stack->stack_elem);
		new_elem->next = stack->stack_elem;
		(stack->stack_elem)->prev = new_elem;
	}
	stack->size += 1;
}

t_stack_elem	*ft_new_e(int value, t_stack *stack_a)
{
	t_stack_elem	*elem;

	elem = malloc(sizeof(t_stack_elem));
	if (!elem)
		return (ft_free(stack_a), ft_error(), NULL);
	elem->value = value;
	elem->next = elem;
	elem->prev = elem;
	return (elem);
}

t_stack_elem	*ft_elem_last(t_stack_elem *elem)
{
	if (elem == NULL)
		return (NULL);
	return (elem->prev);
}

void	ft_stack_init(t_stack *stack_a, t_stack *stack_b)
{
	(*stack_a).stack_elem = NULL;
	(*stack_a).size = 0;
	(*stack_b).stack_elem = NULL;
	(*stack_b).size = 0;
}
