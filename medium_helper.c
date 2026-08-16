/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 18:30:36 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/18 14:30:11 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sqrt(int size)
{
	int	cs;

	cs = 1;
	while (cs * cs < size)
		cs++;
	return (cs);
}

int	find_pos_in_range(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->index >= min && a->index <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

int	find_max_index(t_stack *b)
{
	int	max;

	max = b->index;
	while (b)
	{
		if (b->index > max)
			max = b->index;
		b = b->next;
	}
	return (max);
}

void	rotate_to_top_a(t_stack **a, int pos, t_bench *bench)
{
	int	size;
	int	i;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(a, bench);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rra(a, bench);
	}
}

void	rotate_to_top_b(t_stack **a, int pos, t_bench *bench)
{
	int	size;
	int	i;

	size = stack_size(*a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			rb(a, bench);
	}
	else
	{
		i = 0;
		while (i++ < (size - pos))
			rrb(a, bench);
	}
}
