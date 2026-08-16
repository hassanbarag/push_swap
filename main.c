/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <ignmarti@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:21:57 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/18 17:01:06 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	run_sorting(t_stack **a, t_stack **b, t_config cfg, t_bench *bench)
{
	int	size;

	size = stack_size(*a);
	setup_bench(bench, &cfg, *a);
	if (!is_sorted(*a))
	{
		if (size <= 5)
		{
			sort_small(a, b, bench);
			cfg.strategy = STR_SIMPLE;
		}
		else if (cfg.strategy == STR_SIMPLE)
			simple_min_max(a, b, bench);
		else if (cfg.strategy == STR_MEDIUM)
			chunk_based_sorting(a, b, bench);
		else if (cfg.strategy == STR_COMPLEX)
			complex_algo(a, b, bench);
		else
			adaptive_sort(a, b, bench);
	}
}

/*static void    print_stack(t_stack *a)
{
	while (a)
	{
		printf("%d", a->value);
		a = a->next;
	}
}*/

int	main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_config	cfg;
	t_bench		bench;

	a = NULL;
	b = NULL;
	a = parse_arguments(argc, argv, &cfg);
	if (!a)
		return (0);
	run_sorting(&a, &b, cfg, &bench);
	print_bench(&bench);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
