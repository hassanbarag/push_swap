/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:17 by ignmarti          #+#    #+#             */
/*   Updated: 2025/11/11 10:40:20 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
       The memset() function fills the first n bytes of the memory area pointed 
       to by s with the constant byte c.

RETURN VALUE
       The memset() function returns a pointer to the memory area s.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int	nombres[5] = {5,3,6,4,8};
	int	numeros[5] = {5,3,6,4,8};
	int	i;

	memset(nombres, 0, sizeof(int) * 2);
	ft_memset(numeros, 0, sizeof(int) * 1);
	i = 0;
	while (i < 5)
	{
		printf("%d", nombres[i]);
		i++;
	}
	printf("%s", "\n");
	i=0;
	while (i < 5)
	{
		printf("%d", numeros[i]);
		i++;
	}
	return (0);
}*/
