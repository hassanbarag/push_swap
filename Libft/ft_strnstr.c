/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 10:12:00 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 10:12:20 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The strnstr() function locates the first occurrence of the null-terminated
     string little in the string big, where not more than len characters are 
     searched. Characters that appear after a ‘\0’ character are not searched.
     Since the strnstr() function is a FreeBSD specific API, it should only be 
     used when portability is not a concern.✅️

RETURN VALUES
     If little is an empty string, big is returned ✅️; if little occurs nowhere 
     in big, NULL is returned; otherwise a pointer to the first character of 
     the first occurrence of little is returned. ✅️

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	if (lenlittle == 0)
		return ((char *)big);
	i = 0;
	j = 0;
	while (big [i] && i < len)
	{
		while (little[j] != '\0' && little[j] == big[i + j] && i + j < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		j = 0;
	}
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", ft_strnstr("", "xx", 4294967295));
	return (0);
}*/
