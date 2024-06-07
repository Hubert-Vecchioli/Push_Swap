/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:23:37 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 18:59:14 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_free(t_stack *stack_a)
{
	t_stack_elem	*temp;
	t_stack_elem	*head;

	head = stack_a->stack_elem->prev;
	if (stack_a->stack_elem)
	{
		while (stack_a->stack_elem != head)
		{
			stack_a->stack_elem->value = 0;
			temp = stack_a->stack_elem->next;
			free(stack_a->stack_elem);
			stack_a->stack_elem = temp;
		}
		free(head);
	}
}
