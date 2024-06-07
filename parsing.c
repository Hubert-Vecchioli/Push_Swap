/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:20:52 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 07:40:32 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(int argc, char **argv, t_stack *stack_a)
{
	int		i;

	i = 1;
	if (argc == 1)
		exit(0);// Double check si c est le bon comportement
	if (argc == 2)
		ft_parse_quoted_str(argv, stack_a);
	else
	{
		while (i < argc)
		{
			ft_add_back(stack_a, ft_elem_new(ft_atoi_with_errors(argv[i++]), stack_a)); // a double check
		}
	}
	ft_duplicate_review(stack_a);
}

void	ft_parse_quoted_str(char **argv, t_stack *stack_a)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(argv[1], ' ');

	if (buffer == NULL)
		ft_error();
	while (buffer[i])
		ft_add_back(stack_a, ft_elem_new(ft_atoi_with_errors(buffer[i++]), stack_a)); // a double check
	ft_free_split(buffer, i);
}

int	ft_atoi_with_errors(char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		res = res * 10 + str[i++] - '0';
	}
	if ((sign * res) > 2147483647 ||(sign * res) < -2147483648) // to test!
		ft_error();
	return (sign * res);
}

void	ft_duplicate_review(t_stack *stack_a)
{
	t_stack_elem	*head;
	t_stack_elem	*tmp;
	int				i;

	head = stack_a->stack_elem;
	i = 0;
	while (i < stack_a->size)
	{
		tmp = head->next;
		while (tmp != stack_a->stack_elem)
		{
			if (tmp->value == head->value)
				ft_error();
			tmp = (*tmp).next;
		}
		head = head->next;
		i++;
	}
}

void	**ft_free_split(char **split, int pos)
{
	while (pos >= 0)
	{
		free(split[pos]);
		pos--;
	}
	free(split);
	return (NULL);
}
