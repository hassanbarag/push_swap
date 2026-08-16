/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:36:47 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/18 12:01:19 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	push_chunk_to_b(t_stack **a, t_stack **b, t_range range, t_bench *bench)
{
	int	pos;
	int	mid;

	mid = (range.min + range.max) / 2;
	pos = find_pos_in_range(*a, range.min, range.max);
	while (pos != -1)
	{
		rotate_to_top_a(a, pos, bench);
		pb(a, b, bench);
		if ((*b)->index < mid)
			rb(b, bench);
		pos = find_pos_in_range(*a, range.min, range.max);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = find_max_index(*b);
		pos = find_pos_in_range(*b, max, max);
		rotate_to_top_b(b, pos, bench);
		pa(a, b, bench);
	}
}

void	process_chunks(t_stack **a)
{
	int	*arr;
	int	size;

	size = stack_size(*a);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	index_stack(*a);
	free(arr);
}

void	chunk_based_sorting(t_stack **a, t_stack **b, t_bench *bench)
{
	int		chunk;
	int		min;
	int		max;
	int		size;
	t_range	range;

	if (!*a || is_sorted(*a))
		return ;
	process_chunks(a);
	size = stack_size(*a);
	chunk = ft_sqrt(size);
	min = 0;
	while (min < size)
	{
		max = min + chunk - 1;
		if (max >= size)
			max = size - 1;
		range.min = min;
		range.max = max;
		push_chunk_to_b(a, b, range, bench);
		min += chunk;
	}
	push_back_to_a(a, b, bench);
}
