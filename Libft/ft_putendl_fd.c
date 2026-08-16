/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:58:57 by ignmarti         ###   ########.fr       */
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
void	ft_putendl_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
/*
int	main(void)
{
	char *num1 = "abcde";
	
	ft_putendl_fd(num1, 1);
	printf("%s", num1);
	return (0);
}*/
