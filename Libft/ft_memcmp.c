/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 09:26:36 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 09:27:11 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
       The  memcmp()  function  compares the first n bytes (each interpreted 
       as unsigned char) of the memory areas s1 and s2.✅️

RETURN VALUE
       The memcmp() function returns an integer less than, equal to, or  
       greater  than  zero  if  the first  n bytes of s1 is found, respectively,
       to be less than, to match, or be greater than the first n bytes of s2.✅️

       For a nonzero return value, the sign is determined by the sign of the 
       difference  between  the first pair of bytes (interpreted as unsigned 
       char) that differ in s1 and s2.✅️

       If n is zero, the return value is zero.✅️ 
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	int	numero1;
	int	numero2;
	
	numero1 = ft_memcmp("hola", "holanda", 5);
	numero2 = memcmp("hola", "holanda", 5);
	printf("%d\n", numero1);
	printf("%d\n", numero2);
	return (0);
}*/
