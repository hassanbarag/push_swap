/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 11:00:41 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:59:18 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	free_all(char **split, int j)
{
	while (j > 0)
		free(split[--j]);
	free(split);
}

static int	fill_split(char **split, const char *str, char c)
{
	size_t	i;
	size_t	start;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			start = i;
			while (str[i] && str[i] != c)
				i++;
			split[j] = ft_substr(str, start, i - start);
			if (!split[j])
				return (j);
			j++;
		}
	}
	split[j] = NULL;
	return (-1);
}

static int	count_words(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	**ft_split(const char *str, char c)
{
	char	**split;
	int		words;
	int		res;

	if (!str)
		return (NULL);
	words = count_words(str, c);
	split = malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	res = fill_split(split, str, c);
	if (res != -1)
	{
		free_all(split, res);
		return (NULL);
	}
	return (split);
}
/*
int	main(void)
{
	char **nene;
	int	i;

	nene = ft_split(" 1 5 6 7 8 9 -1", ' ');
	i = 0;
	while (nene[i])
		printf("%s\n", nene[i]);
	return (0);
}*/
