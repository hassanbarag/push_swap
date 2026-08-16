/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:37:21 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/16 14:37:22 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros
	s: La cadena sobre la que iterar.
	f: La función a aplicar sobre cada carácter.
Valor devuelto
	La cadena creada tras el correcto uso de ‘f’ sobre
	cada carácter.
	NULL si falla la reserva de memoria.
Funciones autorizadas
	malloc
Descripción
	Aplica la función ‘f’ a cada carácter de la cadena
	‘s’, pasando su índice como primer argumento y el
	propio carácter como segundo argumento. Se crea una
	nueva cadena (utilizando malloc(3)) para almacenar
	los resultados de las sucesivas aplicaciones de
	‘f’.
*/
/*
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nueva;
	unsigned int	total;
	unsigned int	i;

	i = 0;
	total = ft_strlen(s);
	nueva = malloc(sizeof(char) * total + 1);
	if (!nueva)
		return (NULL);
	while (s[i])
	{
		nueva[i] = f(i, s[i]);
		i++;
	}
	nueva[i] = '\0';
	return (nueva);
}
/*
int	main(void)
{
	char *nombre;
	
	nombre = ft_strmapi("abcde", ft_capital);
	printf("%s\n", nombre);
	return (0);
}*/
