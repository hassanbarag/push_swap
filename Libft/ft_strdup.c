/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:50:47 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/09 09:51:06 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
       The  strdup() function returns a pointer to a new string which is a 
       duplicate of the string s. ✅️
       Memory for the new string is obtained with malloc(3), and can be freed 
       with free(3). ✅️

RETURN VALUE
       On success, the strdup() function returns a pointer to the duplicated 
       string.✅️  It returns NULL if insufficient memory was available, with 
       errno set to indicate the cause of the error. 

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/
char	*ft_strdup(const char *s)
{
	unsigned char	*sdup;
	size_t			lengs;
	size_t			total;
	size_t			i;

	sdup = (unsigned char *)s;
	lengs = ft_strlen(s) + 1;
	total = lengs * sizeof(unsigned char);
	sdup = malloc(total);
	if (!sdup)
		return (NULL);
	i = 0;
	while (i < lengs - 1)
	{
		sdup[i] = (unsigned char)s[i];
		i++;
	}
	sdup[i] = '\0';
	return ((char *)sdup);
}
/*
int	main(void)
{
	char	*cadena = "Holaaa";
	char	*cadena1;
	char	*cadena2;

	cadena1 = ft_strdup(cadena);
	cadena2 = strdup(cadena);
	printf("%s\n", cadena2);
	printf("%s", cadena1);
	free(cadena1);
	free(cadena2);
	return (0);
}*/
