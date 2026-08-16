/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:08:36 by hassamoh          #+#    #+#             */
/*   Updated: 2026/01/27 16:30:27 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// line 30 last = 1
// line 33 prev = 3 wayo marwalba prev last hal talbo ayu kadambeya
// line 36 1 -> 2 -> 3 -> NULL     4 -> NULL
// line 37 last = 4 (kaliya node-ka 4)
// line 38 4 🤝 1 🤝 2 🤝 3

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = NULL;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a, t_bench *bench)
{
	reverse_rotate(a);
	if (bench && bench->enabled)
	{
		bench->rra++;
		bench->total_ops++;
	}
	else
	{
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **b, t_bench *bench)
{
	reverse_rotate(b);
	if (bench && bench->enabled)
	{
		bench->rrb++;
		bench->total_ops++;
	}
	else
	{
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (bench && bench->enabled)
	{
		bench->rrr++;
		bench->total_ops++;
	}
	else
	{
		write(1, "rrr\n", 4);
	}
}
