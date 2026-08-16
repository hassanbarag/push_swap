/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:26:31 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/05 11:26:45 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*
int	main(void)
{
	unsigned char	letra1;
	unsigned char	letra2;

	letra1 = ft_tolower('c');
	letra2 = tolower('c');
	printf("%c\n", letra1);
	printf("%c\n", letra2);
	return (0);
}*/
