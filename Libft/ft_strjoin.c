/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 12:42:17 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 10:00:17 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parámetros
	s1: La primera cadena.
	s2: La cadena a añadir a ‘s1’.
Valor devuelto
	La nueva cadena de caracteres.
	NULL si falla la reserva de memoria.
Descripción
	Reserva memoria (con malloc(3)) y devuelve una
	nueva cadena de caracteres, formada por la
	concatenación de ‘s1’ y ‘s2’.

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total;
	char	*s3;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total = ((len1 + len2 + 1) * sizeof(char));
	s3 = malloc(total);
	if (!s3)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		s3[i] = s1[i];
		i++;
	}
	while (i < (len2 + len1))
	{
		s3[i] = s2[i - len1];
		i++;
	}
	s3[i] = '\0';
	return (s3);
}
/*
int	main(void)
{
	char const	word1[] = "Hola";
	char const	word2[] = "Adios";
	char const	*word3;

	word3 = ft_strjoin(word1, word2);
	printf("%s\n", word3);
	free((void *)word3);
	return (0);
}*/
