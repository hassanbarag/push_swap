/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 11:50:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parametros lst: 
	el nodo a liberar.
	del: un puntero a la funcion utilizada para liberar
	el contenido del nodo.
Valor devuelto 
	Nada
Funciones autorizadas
	free
Descripcion 
	Recibe como parametro un nodo lst y libera la
	memoria del contenido utilizando la funcion del
	dada como parametro. Tambien libera el nodo en si
	mismo, pero no libera el siguiente nodo.

static void	del(void *content)
{
	free(content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
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
