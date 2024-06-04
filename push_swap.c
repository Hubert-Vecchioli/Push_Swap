/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:36:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/04 05:25:02 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	ft_push_swap(argc, argv);
	return (0);
}

void	ft_push_swap(int argc, char **argv)
{
	t_stack stack_a;
	t_stack	stack_b;

	stack_init(&stack_a, &stack_b);
	ft_parse(argc, argv, &stack_a);
	if (!ft_is_sorted(&stack_a))
		ft_sort(&stack_a, &stack_b);
	ft_free(&stack_a, &stack_b);
}
