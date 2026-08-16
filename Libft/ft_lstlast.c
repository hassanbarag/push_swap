/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:55:39 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Prototipo t_list *ft_lstlast(t_list *lst);
Archivos a entregar
-
Parmetros lst: el principio de la lista.
Valor devuelto ltimo nodo de la lista.
Funciones autorizadas
Ninguna
Descripcin Devuelve el ltimo nodo de la lista.
*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
int main(void)
{
	t_list *a = ft_lstnew("A");
	t_list *b = ft_lstnew("B");
	t_list *c = ft_lstnew("C");
	t_list *d = ft_lstnew("D");
	
	a->next = b;
	b->next = c;
	c->next = d;
	printf("%s\n", ft_lstlast(a)->content);
	return (0);
	
	//printf("%s\n", (char *)b->content); // NEW
}*/
