/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 11:50:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contar_nums(int n)
{
	int	leng;

	leng = 0;
	if (n == 0)
		leng = 1;
	if (n < 0)
		leng = leng + 1;
	while (n != 0)
	{
		leng++;
		n /= 10;
	}
	return (leng);
}

char	*ft_itoa(int n)
{
	int		leng;
	long	num;
	char	*numero;

	num = n;
	leng = contar_nums(num);
	numero = malloc(sizeof(char) * leng + 1);
	if (!numero)
		return (NULL);
	numero[leng] = '\0';
	if (num < 0)
	{
		numero[0] = '-';
		num = -num;
	}
	while (leng-- && numero[leng] != '-')
	{
		numero[leng] = (num % 10) + '0';
		num /= 10;
	}
	return (numero);
}
/*
int	main(void)
{
	char	*num1;

	num1 = ft_itoa(9);
	printf("%s", num1);
	free(num1);
	return (0);
}*/
