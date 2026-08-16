/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:56:51 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parmetros lst: el principio de la lista.
Valor devuelto La longitud de la lista.
Funciones autorizadas
Ninguna
Descripcin Cuenta el nmero de nodos de una lista.


t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
*/
int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
int main(void)
{
	t_list *a = ft_lstnew("A");
	t_list *b = ft_lstnew("B");
	t_list *c = ft_lstnew("C");
	t_list *d = ft_lstnew("D");
	int	count;
	
	count = 0;
	a->next = b;
	b->next = c;
	c->next = d;
	
	count = ft_lstsize(a);
	
	printf("%d\n", count); // NEW
	return (0);
}*/
