/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 09:49:28 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/07 20:03:43 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	push(b, a);
	if (bench && bench->enabled)
	{
		bench->pa++;
		bench->total_ops++;
	}
	else
	{
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack **a, t_stack **b, t_bench *bench)
{
	push(a, b);
	if (bench && bench->enabled)
	{
		bench->pb++;
		bench->total_ops++;
	}
	else
	{
		write(1, "pb\n", 3);
	}
}
