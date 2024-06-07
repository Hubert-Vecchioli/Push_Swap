/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 09:06:47 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 19:52:03 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	ft_strcmp(const char *str1, const char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
	{
		i++;
	}
	return ((int)((unsigned char)str1[i] - (unsigned char)str2[i]));
}

static int	ft_parse_instruct(t_stack *stack_a, t_stack *stack_b, char *instruction)
{
	if (!ft_strcmp(instruction, "sa\n"))
		sa(stack_a, 0);
	else if (!ft_strcmp(instruction, "sb\n"))
		sb(stack_b, 0);
	else if (!ft_strcmp(instruction, "ss\n"))
		ss(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pa\n"))
		pa(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "pb\n"))
		pb(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "ra\n"))
		ra(stack_a, 0);
	else if (!ft_strcmp(instruction, "rb\n"))
		rb(stack_b, 0);
	else if (!ft_strcmp(instruction, "rr\n"))
		rr(stack_a, stack_b, 0);
	else if (!ft_strcmp(instruction, "rra\n"))
		rra(stack_a, 0);
	else if (!ft_strcmp(instruction, "rrb\n"))
		rrb(stack_b, 0);
	else if (!ft_strcmp(instruction, "rrr\n"))
		rrr(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}

static void	ft_clean_checker(t_stack *stack_a, t_stack *stack_b, char *line, int fd)
{
	free(line);
	close(fd);
	ft_free(stack_a);
	ft_free(stack_b);
	ft_error();
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	*line;

	if (argc < 2)
		return (ft_error(), 0);
	ft_stack_init(&stack_a, &stack_b);
	ft_parse(argc, argv, &stack_a);
	stack_a.max_size = stack_a.size;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line || !*line)
			break ;
		if (!ft_parse_instruct(&stack_a, &stack_b, line))
			ft_clean_checker(&stack_a, &stack_b, line, STDIN_FILENO);
		free(line);
	}
	if (stack_a.max_size != stack_a.size || !ft_is_sorted(&stack_a))
		ft_putstr_fd("KO\n", 2);
	else
		ft_putstr_fd("OK\n", 2);
	close(STDIN_FILENO);
	ft_free(&stack_a);
	ft_free(&stack_b);
}