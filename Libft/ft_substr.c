/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:41:11 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/09 10:41:47 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Descripción:
	Reserva memoria (con malloc(3)) y devuelve una subcadena de caracteres 
	de la cadena ‘s’. La subcadena comienza en el índice ‘start ’ y tiene
	una longitud máxima ‘len ’.
Parámetros:
	s: La cadena original desde la que se crea la
	subcadena.
	start: El índice del carácter en ‘s’ desde el que
	empieza la subcadena.
	len: La longitud máxima de la subcadena.
Valor devuelto:
	La subcadena de caracteres resultante.
	NULL si falla la reserva de memoria.

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	unsigned char	*sdup;
	size_t			lengs;
	size_t			total;
	size_t			i;

	sdup = (unsigned char *)s;
	lengs = ft_strlen(s) + 1;
	total = lengs * sizeof(unsigned char);
	sdup = malloc(total);
	if (!sdup)
		return (NULL);
	i = 0;
	while (i < lengs - 1 && s[i])
	{
		sdup[i] = (unsigned char)s[i];
		i++;
	}
	sdup[i] = '\0';
	return ((char *)sdup);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*cador;
	size_t			lengs;
	size_t			i;
	size_t			total;

	if (!s)
		return (NULL);
	lengs = ft_strlen(s);
	if (start >= lengs)
		return (ft_strdup(""));
	if (len > lengs - start)
		len = lengs - start;
	total = (len + 1) * sizeof (char);
	cador = malloc(total);
	if (!cador)
		return (NULL);
	i = 0;
	while (i < len && s[i])
	{
		cador[i] = s[i + start];
		i++;
	}
	cador[i] = '\0';
	return ((char *)cador);
}
/*
int	main(void)
{
	char	*cadenaoriginal = "hola";
	char	*subcadena;
	
	subcadena = ft_substr(cadenaoriginal, 0, SIZE_MAX);
	printf("%s\n", subcadena);
	free(subcadena);
	return (0);
}*/
