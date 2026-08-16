/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 10:56:33 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/09 16:17:26 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value)
{
	t_stack	*item;

	item = (t_stack *)malloc(sizeof(t_stack));
	if (!item)
		return (NULL);
	item->value = value;
	item->index = 0;
	item->next = NULL;
	return (item);
}

void	stack_add_back(t_stack **stack, t_stack *new_item)
{
	t_stack	*bottom;

	if (!stack || !new_item)
		return ;
	if (*stack == NULL)
	{
		*stack = new_item;
		return ;
	}
	bottom = *stack;
	while (bottom->next)
	{
		bottom = bottom->next;
	}
	bottom->next = new_item;
}

void	stack_add_front(t_stack **stack, t_stack *new_item)
{
	if (!stack || !new_item)
		return ;
	new_item->next = *stack;
	*stack = new_item;
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}
