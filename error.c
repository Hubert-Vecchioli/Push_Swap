/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:23:37 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/05 11:01:30 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free(t_stack *stack_a)
{
	t_stack_elem	temp;

	if (stack_a->stack_elem)
		while (stack_a->stack_elem)
		{
			temp = stack_a->stack_elem->next
			stack_a->stack_elem->value = 0
			free(stack_a->stack_elem);
			stack_a->stack_elem = temp
		}
}