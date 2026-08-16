/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 11:50:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parmetros
	s: La cadena a enviar.
	fd: El descriptor de archivo sobre el que escribir.
Valor devuelto
	Nada
Funciones autorizadas
	write
Descripcin	
	Enva la cadena s al descriptor de archivo dado,
	seguido de un salto de lnea.
*/
void	ft_putnbr_fd(int n, int fd)
{
	long int	numero;
	int			b;

	numero = n;
	b = 0;
	if (numero < 0)
	{
		numero *= -1;
		write(fd, "-", 1);
	}
	if (numero > 9)
		ft_putnbr_fd((numero / 10), fd);
	b = (numero % 10) + '0';
	write(fd, &b, 1);
}
/*
int	main(void)
{
	int num1 = 12;
	
	ft_putnbr_fd(num1, 1);
	return (0);
}*/
