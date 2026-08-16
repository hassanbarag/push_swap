/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:02:03 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/05 11:02:25 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
int	main(void)
{
	unsigned char	letra1;
	unsigned char	letra2;

	letra1 = ft_toupper('C');
	letra2 = toupper('C');
	printf("%c\n", letra1);
	printf("%c\n", letra2);
	return (0);
}*/
