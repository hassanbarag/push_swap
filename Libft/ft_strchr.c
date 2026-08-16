/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 13:22:59 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/05 13:23:06 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The  strchr()  function  returns  a  pointer to the first occurrence of 
       the character c in the string s.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched 
       character or NULL if the character  is  not found.  The terminating null 
       byte is considered part of the string, so that if c is specified as '\0',
       these functions return a pointer to the terminator.
*/

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (p[i])
	{
		if (p[i] == (unsigned char)c)
			return ((char *)&p[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&p[i]);
	return (NULL);
}
/*
int	main(void)
{
	printf("%s\n", strchr("hola", 'o'));
	printf("%s", ft_strchr("hola", 'o'));
	return (0);
}*/
