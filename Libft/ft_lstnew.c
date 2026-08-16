/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:56:30 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
/*
int main(void)
{
	t_list *nodo;
	
	nodo = ft_lstnew("Hola bebe");
	
	if (!nodo)
	{
		printf("No se pudo crear el nodo ??\n");
		return (1);
	}
	
	printf("Contenido: %s\n", (char *)nodo->content);
	printf("Next: %p\n", (void *)nodo->next);
	printf("Direccion del nodo: %p\n", (void *)nodo);
	
	free(nodo);
	return (0);
}*/
