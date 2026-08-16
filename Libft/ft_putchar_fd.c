/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 16:43:28 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:58:29 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parámetros
	c: El carácter a enviar.
	fd: El descriptor de archivo sobre el que escribir.
Valor devuelto
	Nada
Funciones autorizadas
	write
Descripción
	Envía el carácter ‘c’ al descriptor de archivo
	(file descriptor ) especificado.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('c', 1);
	return (0);
}*/
