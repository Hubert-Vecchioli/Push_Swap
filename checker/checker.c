/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:06:47 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 09:15:11 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack	stack_b;
	char	*line;

	if (ac < 2)
		return (0);
	ft_stack_init(&stack_a, &stack_b);
	ft_parse(argc, argv, &stack_a);
	line = get_next_line(STDIN_FILENO);
		if (!line || !*line)
			break ;
	if (!ft_is_sorted(&stack_a))
		ft_sort(&stack_a, &stack_b);
	if (stack_b->size != 0 || !ft_is_sorted(&stack_a))
		write(1, "KO\n", 3);
	else if (stack_b->size == 0 && ft_is_sorted(&stack_a))
		write(1, "OK\n", 3);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}