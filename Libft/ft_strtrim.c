/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 14:13:03 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/09 14:13:05 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s2;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (s1[end - 1] && is_in_set(s1[end - 1], set))
		end--;
	s2 = ft_substr(s1, start, (end - start));
	return ((char *)s2);
}
/*
int	main(void)
{
	char	*sent;
	char	*trim;

	sent = "abcabcpetardoabcabc";
	trim = ft_strtrim(sent, "abc");
	printf("%s\n", trim);
	return (0);
}*/
