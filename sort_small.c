/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 12:04:59 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/08 12:27:54 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a, t_bench *bench)
{
	if (!(*a) || !(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, bench);
		return ;
	}
}

void	sort_3(t_stack **a, t_bench *bench)
{
	int	max;

	max = find_max(*a);
	if (is_sorted(*a))
		return ;
	if ((*a)->value == max)
		ra(a, bench);
	else if ((*a)->next->value == max)
		rra(a, bench);
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

void	sort_4(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min;

	min = find_min(*a);
	if (is_sorted(*a))
		return ;
	while ((*a)->value != min)
	{
		if ((*a)->next && (*a)->next->value == min)
			sa(a, bench);
		else
			ra(a, bench);
	}
	pb(a, b, bench);
	sort_3(a, bench);
	pa(a, b, bench);
}

void	sort_5(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min;

	min = find_min(*a);
	if (is_sorted(*a))
		return ;
	while ((*a)->value != min)
	{
		if ((*a)->next && (*a)->next->value == min)
			sa(a, bench);
		else
			ra(a, bench);
	}
	pb(a, b, bench);
	min = find_min(*a);
	while ((*a)->value != min)
	{
		if ((*a)->next && (*a)->next->value == min)
			sa(a, bench);
		else
			ra(a, bench);
	}
	pb(a, b, bench);
	sort_3(a, bench);
	pa(a, b, bench);
	pa(a, b, bench);
}

void	sort_small(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	if (size == 2)
		sort_2(a, bench);
	else if (size == 3)
		sort_3(a, bench);
	else if (size == 4)
		sort_4(a, b, bench);
	else if (size == 5)
		sort_5(a, b, bench);
}
