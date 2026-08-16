/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:54:42 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parmetros lst: el nodo a liberar.
del: un puntero a la funcin utilizada para liberar
el contenido del nodo.
Valor devuelto Nada
Funciones autorizadas
free
Descripcin Recibe como parmetro un nodo lst y libera la
memoria del contenido utilizando la funcin del
dada como parmetro. Tambin libera el nodo en s
mismo, pero no libera el siguiente nodo.

static void	del(void *content)
{
	free(content);
}
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}
/*
int main(void)
{
	t_list *a = ft_lstnew(strdup("A"));
	t_list *b = ft_lstnew(strdup("B"));
	t_list *c = ft_lstnew(strdup("C"));
	t_list *d = ft_lstnew(strdup("D"));
	
	a->next = b;
	b->next = c;
	c->next = d;
	printf("%d\n", ft_lstsize(a));
	printf("%s\n", (char *)c->content);
	b->next = c->next;
	ft_lstdelone(c, del);
	printf("%s\n", (char *)c->content);
	printf("%d\n", ft_lstsize(a));
	return (0);
}*/
