/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 11:02:10 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/18 16:33:35 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort_simple(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench && bench->enabled)
	{
		bench->strategy_name = "simple";
		bench->complexity = "O(n²)";
	}
	simple_min_max(a, b, bench);
}

void	adaptive_sort_medium(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench && bench->enabled)
	{
		bench->strategy_name = "medium";
		bench->complexity = "O(n√n)";
	}
	chunk_based_sorting(a, b, bench);
}

void	adaptive_sort_complex(t_stack **a, t_stack **b, t_bench *bench)
{
	if (bench && bench->enabled)
	{
		bench->strategy_name = "complex";
		bench->complexity = "O(n log n)";
	}
	complex_algo(a, b, bench);
}

void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench)
{
	double	disorder;

	index_stack(*a);
	disorder = compute_disorder(*a);
	if (bench && bench->enabled)
		bench->disorder = disorder;
	if (disorder < 0.2)
		adaptive_sort_simple(a, b, bench);
	else if (disorder < 0.5)
		adaptive_sort_medium(a, b, bench);
	else
		adaptive_sort_complex(a, b, bench);
}
