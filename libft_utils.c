/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvecchio <hvecchio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 00:09:17 by hvecchio          #+#    #+#             */
/*   Updated: 2024/06/07 07:26:34 by hvecchio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t n)
{
	char		*copy_str;
	size_t		i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		n = 0;
	if (ft_strlen(s) - start < n)
		n = ft_strlen(s) - start;
	copy_str = malloc((n + 1) * sizeof(char));
	if (copy_str == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		copy_str[i] = s[start];
		i++;
		start++;
	}
	copy_str[i] = 0;
	return (copy_str);
}

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static int	ft_count_word_len(const char *s, char c, int pos)
{
	int	count;

	count = 0;
	while (s[pos] && s[pos] != c)
	{
		pos++;
		count++;
	}
	return (count);
}

static char	**ft_split_free(char **split, int pos)
{
	while (pos >= 0)
	{
		free(split[pos]);
		pos--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		j;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (split == NULL || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (ft_count_word_len(s, c, i))
		{
			split[j] = ft_substr(s, i, ft_count_word_len(s, c, i));
			if (split[j] == NULL)
				return (ft_split_free(split, j));
			j++;
		}
		i = i + ft_count_word_len(s, c, i);
	}
	split[j] = 0;
	return (split);
}

static void	ft_putchar_fd(char c, int fd)
{
	if (fd >= 0)
		write(fd, &c, sizeof(char));
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb / 10 != 0)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd(nb % 10 + '0', fd);
}

