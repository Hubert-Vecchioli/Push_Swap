/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 02:56:33 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 19:50:11 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*result;

	if (size != 0 && n > (size_t) - 1 / size)
		return (NULL);
	result = malloc(n * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, (n * size));
	return (result);
}

void	ft_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
}
