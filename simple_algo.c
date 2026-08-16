/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:35:55 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/05 13:17:12 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_min_max(t_stack **a, t_stack **b, t_bench *bench)
{
	int	min;
	int	pos;
	int	size;

	if (!a || !*a || is_sorted(*a))
		return ;
	while (*a)
	{
		min = find_min(*a);
		pos = find_position(*a, min);
		size = stack_size(*a);
		if (pos <= size / 2)
		{
			while ((*a)->value != min)
				ra(a, bench);
		}
		else
		{
			while ((*a)->value != min)
				rra(a, bench);
		}
		pb(a, b, bench);
	}
	while (*b)
		pa(a, b, bench);
}
