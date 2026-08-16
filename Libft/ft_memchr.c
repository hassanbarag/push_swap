/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:04:44 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 09:05:15 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
The memchr() function  scans  the initial n bytes of the memory area pointed 
to by s for the first instance of c.  Both c and the bytes of the memory area
pointed to by s are  interpreted as unsigned char.

The memchr() and memrchr() functions return a pointer to the matching  byte  
or  NULL  if  the character does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return (&p[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	*letra1;
	char	*letra2;

	letra1 = memchr("hola", 'o', 2);
	letra2 = ft_memchr("hola", 'o', 2);
	printf("%s\n", letra1);
	printf("%s\n", letra2);
	return (0);
}*/
