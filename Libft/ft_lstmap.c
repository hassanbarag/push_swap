/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:56:01 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
Parámetros lst: 
	lst: un puntero a un nodo.
	f: la dirección de un puntero a una función usada
	en la iteración de cada elemento de la lista.
	del: un puntero a función utilizado para eliminar
	el contenido de un nodo, si es necesario.
Valor devuelto
	La nueva lista.
	NULL si falla la reserva de memoria.
Funciones autori-
zadas
	malloc, free
Descripción
	Itera la lista ‘lst’ y aplica la función ‘f’ al
	contenido de cada nodo. Crea una lista resultante
	de aplicar sucesivamente la función ‘f’ a cada
	nodo. La función ‘del’ se utiliza para eliminar
	el contenido de un nodo si es necesario.

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

static void	del(void *content)
{
	free(content);
}

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

static void	*ft_tolow(void *c)
{
	size_t	i;
	unsigned char *p = (unsigned char *)c;
	
	i = 0;
	while (p[i])
	{
		if (p[i] >= 'A' && p[i] <= 'Z')
			p[i] += 32;
		i++;
	}
	return (c);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*nodonuevo;
	void	*contenidonuevo;

	if (!lst || !f || !del)
		return (NULL);
	lst2 = NULL;
	while (lst)
	{
		contenidonuevo = f(lst->content);
		nodonuevo = ft_lstnew(contenidonuevo);
		if (!nodonuevo)
		{
			del(contenidonuevo);
			ft_lstclear(&nodonuevo, del);
		}
		ft_lstadd_back(&lst2, nodonuevo);
		lst = lst->next;
	}
	return (lst2);
}
/*
int	main(void)
{
	t_list *a = ft_lstnew(strdup("AASERRADEROOOOOOSODFOSADOFDS"));
	t_list *b = ft_lstnew(strdup("BB"));
	t_list *c = ft_lstnew(strdup("CCJAHGJJKSGSKGHKSFDSDGSF"));
	t_list *d = ft_lstnew(strdup("DD"));
	t_list *lista2;
	int	i;
	
	a->next = b;
	b->next = c;
	c->next = d;
	lista2 = ft_lstmap(a, ft_tolow, del);
	i = 0;
	while (lista2)
	{
		printf("%s\n", (char *)lista2->content);
		lista2 = lista2->next;
	}
	return (0);
}*/
/*
int main(void)
{
    t_list n1;
    t_list n2;
    t_list n3;
    t_list *tmp;

    n1.content = "A";
    n1.next = &n2;
    n2.content = "B";
    n2.next = &n3;
    n3.content = "C";
    n3.next = NULL;

    tmp = &n1;
    while (tmp)
    {
        char *str = tmp->content;
        while (*str)
        {
            write(1, str, 1);
            str++;
        }
        write(1, "\n", 1);
        tmp = tmp->next;
    }

    return 0;
}*/
