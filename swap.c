/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 11:03:53 by hassamoh          #+#    #+#             */
/*   Updated: 2026/01/27 15:42:14 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//line 27 numberka kowad waxa ku xegi kadhig numberka labad waxa ku xiga

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_bench *bench)
{
	swap(a);
	if (bench && bench->enabled)
	{
		bench->sa++;
		bench->total_ops++;
	}
	else
	{
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack **b, t_bench *bench)
{
	swap(b);
	if (bench && bench->enabled)
	{
		bench->sb++;
		bench->total_ops++;
	}
	else
	{
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	swap(a);
	swap(b);
	if (bench && bench->enabled)
	{
		bench->ss++;
		bench->total_ops++;
	}
	else
	{
		write(1, "ss\n", 3);
	}
}
