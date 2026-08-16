/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:37:10 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/08 13:18:14 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_index_bits(t_stack *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_lsd(t_stack **a, t_stack **b, t_bench *bench)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = stack_size(*a);
	max_bits = max_index_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, bench);
			else
				pb(a, b, bench);
			j++;
		}
		while (*b)
			pa(a, b, bench);
		i++;
	}
}

void	complex_algo(t_stack **a, t_stack **b, t_bench *bench)
{
	index_stack(*a);
	radix_lsd(a, b, bench);
}
