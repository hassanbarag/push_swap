/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/27 09:55:13 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
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

static void	ft_tolow(void *c)
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
}
*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
int main(void)
{
	t_list *a = ft_lstnew(strdup("AASERRADEROOOOOOSODFOSADOFDS"));
	t_list *b = ft_lstnew(strdup("BB"));
	t_list *c = ft_lstnew(strdup("CCJAHGJJKSGSKGHKSFDSDGSF"));
	t_list *d = ft_lstnew(strdup("DD"));

	a->next = b;
	b->next = c;
	c->next = d;
	ft_lstiter(a, ft_tolow);
	printf("%s\n", (char *)a->content);
	printf("%s\n", (char *)b->content);
	printf("%s\n", (char *)c->content);
	printf("%s\n", (char *)d->content);
	return (0);
}*/
