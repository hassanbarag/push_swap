/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 11:46:01 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:57:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*DESCRIPTION
       The  memcpy()  function  copies  n bytes from memory area src to memory
       area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
       memory areas do overlap.*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	unsigned long	i;

	if (dest == src || n == 0)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	int	arr1[5] = {0, 0, 0, 0, 0};
	int	arr2[5] = {0, 0, 0, 0, 0};
	int	arr3[5] = {8, 3, 6, 4, 7};
	int	i;
	int	d = NULL;
	int	e = NULL;
	
	memcpy(d, e, 8);
	ft_memcpy(arr2, arr3, 8);
	i=0;
	while (i < 5)
	{
		printf("%d ", arr1[i]);
		printf("%d ", arr2[i]);
		printf("%d", arr3[i]);
		printf("%c", '\n');
		i++;
	}
}*/
