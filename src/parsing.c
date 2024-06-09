/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:20:52 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/09 17:46:22 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parse(int ac, char **av, t_stack *stack_a)
{
	int		i;

	i = 1;
	if (ac == 1)
		exit(0);
	if (ac == 2)
		ft_parse_quoted_str(av, stack_a);
	else
	{
		while (i < ac)
		{
			ft_add_back(stack_a, ft_new_e
				(ft_atoi(av[i++], stack_a, NULL), stack_a, NULL));
		}
	}
	ft_duplicate_review(stack_a);
}

void	ft_parse_quoted_str(char **av, t_stack *stack_a)
{
	char	**buffer;
	int		i;

	i = 0;
	buffer = ft_split(av[1], ' ');
	if (buffer == NULL)
		ft_error();
	while (buffer[i])
		ft_add_back(stack_a, ft_new_e
			(ft_atoi(buffer[i++], stack_a, buffer), stack_a, buffer));
	ft_free_split(buffer);
}

int	ft_atoi(char *str, t_stack *stack_a, char **buffer)
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
			return (ft_free(stack_a, buffer), ft_error(), 0);
		res = res * 10 + str[i++] - '0';
	}
	if ((sign * res) > 2147483647 || (sign * res) < -2147483648)
		return (ft_free(stack_a, buffer), ft_error(), 0);
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
			{
				ft_free(stack_a, NULL);
				ft_error();
			}
			tmp = (*tmp).next;
		}
		head = head->next;
		i++;
	}
}
