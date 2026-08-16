/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:37:24 by ignmarti          #+#    #+#             */
/*   Updated: 2025/12/30 12:37:26 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  memmove() function  copies n bytes from memory area src to memory area
	dest.  The memory areas may overlap: copying takes place as though the 
	bytes in src are first copied into a temporary array that does not 
	overlap src or dest, and the bytes are then copied from the temporary 
	array to dest.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	if (dest == src || n == 0)
		return (dest);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		if (pdest > psrc)
			pdest[n - 1 - i] = psrc[n - 1 - i];
		if (pdest <= psrc)
			pdest[i] = psrc[i];
		i++;
	}
	return (pdest);
}
/*
int	main(void)
{
	//char	palabra1[5] = "Estop";
	char	palabra2[5] = "Estop";
	
	//memmove(palabra1 + 2, palabra1, 3);
	//memmove(((void*)0), ((void*)0), 5);
	ft_memmove(palabra2 + 2, palabra2, 3);
	//printf("%s ", palabra1);
	//printf("%c", '\n');
	printf("%s ", palabra2);
	return (0);
}*/
