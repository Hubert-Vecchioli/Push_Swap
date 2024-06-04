/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:41:43 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/04 13:51:01 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_init(t_stack *stack_a, t_stack *stack_b)
{
	(*stack_a).stack_elem = NULL;
	(*stack_a).size = 0;
	(*stack_b).stack_elem = NULL;
	(*stack_b).size = 0;
}

void ft_stack_elem_init(int nbr)
{
	t_stack_elem	*new;
	
	new = malloc(sizeof(t_stack_elem));
	if (new == NULL)
		return (NULL);
	
	(*new).value = nbr;
	(*new).index = 0;
	(*new).next	= new;
	(*new).prev = new;
	return (new); 
}