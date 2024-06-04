/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:23:37 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/04 05:09:00 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	// ft_free ici ?
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_free(t_stack *stack_a, t_stack *stack_b)
{
	// free tt les elems
}