/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:53:30 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/05 09:54:23 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lengd;
	size_t	lengs;

	lengd = 0;
	lengs = ft_strlen(src);
	while (lengd < size && dst[lengd])
	{
		lengd++;
	}
	if (lengd == size)
		return (size + lengs);
	i = 0;
	while (src[i] && i < size - 1 - lengd)
	{
		dst[i + lengd] = src[i];
		i++;
	}
	dst[i + lengd] = '\0';
	return (lengd + lengs);
}
/*
int	main(void)
{
	char	dest[10] = "Carnal";
	char	source[6] = "Adios";

	printf("%zu\n", ft_strlcat(dest, source, 10));
	printf("%s", dest);
	return (0);
}*/
