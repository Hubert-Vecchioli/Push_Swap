/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:36:07 by hvecchio          #+#    #+#             */
/*   Updated: 2024/05/31 15:41:18 by hvecchio         ###   ########.fr       */
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
	// Review input
	if (!ft_review_ps_input(argc, argv))
		return ;
	// init
	// parse
	// check if sorted
	// sort
	// check if sorted
	// print
	// free
}

int	ft_push_swap(int argc, char **argv)
{
	if (argv == 1)
		return (ft_error(), 0);

}

void	ft_error(void)
{
	write(2, "Error\n", 6);
}

typedef struct s_stack
{
	t_stack_elem	*elems;
	int				size;
}	t_stack;