/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:36:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/03 13:12:53 by hvecchio         ###   ########.fr       */
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

	if (!ft_review_ps_input(argc, argv))
		return ;
	stack_init(&stack_a, &stack_b);
	// parse
		// Doublon
		// is nombre
		// is int
	// Protection malloc elem
	// check if sorted
	// sort
	// check if sorted
	// print
	// free
}

void ft_parse(int argc, char **argv, t_stack *stack_a)
{
	t_stack_elem new_elem;
	int		i;

	i = 0;
	while (++i < ac)
		// split
		// protection
		// check ??
		// add stec elem
		// free

}