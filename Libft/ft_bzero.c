/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 15:58:47 by ignmarti          #+#    #+#             */
/*   Updated: 2025/12/29 15:58:56 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	int	nombres[5] = {5,3,6,4,8};
	int	numeros[5] = {5,3,6,4,8};
	int	i;

	bzero(nombres, 8);
	ft_bzero(numeros, 8);
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
	// puede ser 0 o '\0' lo que se quiera... pero no NULL;
	return (0);
}*/
