/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 15:01:26 by hassamoh          #+#    #+#             */
/*   Updated: 2026/01/31 10:42:29 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a->value = lambarka ku qoran sanduuqa
// a = far gacantaada ku tilmaamaya sanduuq

#include "push_swap.h"

int	find_min(t_stack *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	find_position(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == value)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
