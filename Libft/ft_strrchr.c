/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:23:01 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/05 14:31:11 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The strrchr() function returns a pointer to the last occurrence of  the  
       character  c  in  the
       string s.

RETURN VALUE
       The strchr() and strrchr() functions return a pointer to the matched 
       character or NULL if  the character  is  not found.  The terminating
       null byte is considered part of the string, so that if c is specified 
       as '\0', these functions return a pointer to the terminator.

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = ft_strlen(p);
	while (i >= 0)
	{
		if (p[i] == (char)c)
			return (&p[i]);
		i--;
	}
	if ((char)c == '\0')
		return (&p[i]);
	return (NULL);
}
/*
int	main(void)
{
	char	*letra1;
	char	*letra2;
	
	letra1 = strrchr("h loa", '\0');
	letra2 = ft_strrchr("Hlolla", '\0');
	printf("%s\n", letra1);
	printf("%s\n", letra2);
	return (0);
}*/
