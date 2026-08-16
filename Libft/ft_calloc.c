/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:43:57 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:51:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The malloc() function allocates size bytes and returns a pointer to the 
       allocated memory.  The
       memory is not initialized.  If size is 0, then malloc()  returns  either
         NULL,  or  a  unique
       pointer value that can later be successfully passed to free().

       The free() function frees the memory space pointed to by ptr, which 
       must have been returned by
       a previous call to malloc(), calloc(), or realloc().  Otherwise, or 
       if free(ptr)  has  already
       been called before, undefined behavior occurs.  If ptr is NULL, no 
       operation is performed.

       The  calloc()  function allocates memory for an array of nmemb elements 
       of size bytes each and
       returns a pointer to the allocated memory.  The memory is set to zero
       .  If nmemb or size is 0,
       then  calloc()  returns  either NULL, or a unique pointer value that 
       can later be successfully
       passed to free().  If the multiplication of nmemb and size would resu
       lt in  integer  overflow,
       then calloc() returns an error.  By contrast, an integer overflow wou
       ld not be detected in the
       following call to malloc(), with the result that an incorrectly sized
        block of memory would be
       allocated:

           malloc(nmemb * size);

RETURN VALUE
       The  malloc()  and calloc() functions return a pointer to the allocated
        memory, which is suit‐
       ably aligned for any built-in type.  On error, these functions return
        NULL.  NULL may also  be
       returned by a successful call to malloc() with a size of zero, or 
       by a successful call to cal‐
       loc() with nmemb or size equal to zero.

       The free() function returns no value.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	int	*nums1;
	int	*nums2;
	int	i;
	
	i = 0;
	//nums1 = ft_calloc(0, 8);
	nums2 = calloc(0, sizeof(int));
	while (i < 10)
	{
		//printf("%d ", nums1[i]);
		printf("%d\n", nums2[i]);
		i++;
	}
	free(nums1);
	free(nums2);
	return (0);
}*/
