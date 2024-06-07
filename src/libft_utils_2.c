/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:16:55 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 00:21:18 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (str[lenght])
	{
		lenght++;
	}
	return (lenght);
}
