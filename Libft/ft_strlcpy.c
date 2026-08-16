/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:40:17 by ignmarti          #+#    #+#             */
/*   Updated: 2025/11/11 10:40:20 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
     The strlcpy() and strlcat() functions copy and concatenate strings respect
     ively.  They are designed to be safer, more consistent, and less error prone
     replacements for strncpy(3) andstrncat(3). Unlike those functions, strlcpy()
     and strlcat() take the full size of the buffer(not just the length) and 
     guarantee to NUL-terminate the result (as long as size is larger than
     0 or, in the case of strlcat(), as long as there is at least one byte fre
     e in dst).  Note that a byte for the NUL should be included in size. Also
     note that strlcpy() and strlcat() only operate on true “C” strings.  This 
     means that for strlcpy() src must be NUL-terminated and for strlcat() both 
     src and dst must be NUL-terminated.

     The strlcpy() function copies up to size - 1 characters from the NUL-ter
     minated string src to
     dst, NUL-terminating the result.
RETURN VALUES
     The strlcpy() and strlcat() functions return the total length of the str
     ing they tried to create.  For strlcpy() that means the length of src.

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
	{
		return (ft_strlen(src));
	}
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	dest[12];
	char	source[9] = "Adioss";

	printf("%zu\n", ft_strlcpy(dest, source, 0));
	printf("%s", dest);
	return (0);
}*/
