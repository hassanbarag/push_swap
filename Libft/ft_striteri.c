/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:52:27 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:59:56 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros s:
	La cadena sobre la que iterar.
	f: La función a aplicar sobre cada carácter.
Valor devuelto
	Nada
Funciones autorizadas
	Ninguna
Descripción
	Aplica la función ‘f’ a cada carácter de la string
	‘s’, pasando como parámetros el índice de cada
	carácter dentro de ‘s’ y la dirección del propio
	carácter, que puede modificarse si es necesario.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
int	main(void)
{
	char nombre[] = "abcdefg";
	
	ft_striteri(nombre, ft_capital);
	printf("%s\n", nombre);
	return (0);
}*/
