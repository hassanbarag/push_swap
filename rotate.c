/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:46:56 by hassamoh          #+#    #+#             */
/*   Updated: 2026/01/26 12:13:24 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// line 26 first = 2 5 9 6
// line stack 5 9 6

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = first->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_stack **a, t_bench *bench)
{
	rotate(a);
	if (bench && bench->enabled)
	{
		bench->ra++;
		bench->total_ops++;
	}
	else
	{
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack **b, t_bench *bench)
{
	rotate(b);
	if (bench && bench->enabled)
	{
		bench->rb++;
		bench->total_ops++;
	}
	else
	{
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	rotate(a);
	rotate(b);
	if (bench && bench->enabled)
	{
		bench->rr++;
		bench->total_ops++;
	}
	else
	{
		write(1, "rr\n", 3);
	}
}
