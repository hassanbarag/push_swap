/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:03:58 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/18 08:02:58 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench, t_config *cfg)
{
	if (!bench)
		return ;
	ft_bzero(bench, sizeof(t_bench));
	if (cfg && cfg->bench)
		bench->enabled = 1;
	bench->strategy_name = NULL;
	bench->complexity = NULL;
}

void	set_bench_info(t_bench *bench, t_config *cfg)
{
	if (bench->enabled)
	{
		if (cfg->strategy == STR_SIMPLE)
		{
			bench->strategy_name = "simple";
			bench->complexity = "O(n²)";
		}
		else if (cfg->strategy == STR_MEDIUM)
		{
			bench->strategy_name = "medium";
			bench->complexity = "O(n log n)";
		}
		else if (cfg->strategy == STR_COMPLEX)
		{
			bench->strategy_name = "complex";
			bench->complexity = "O(n log n)";
		}
		else
		{
			bench->strategy_name = "adaptive";
			bench->complexity = "varies";
		}
	}
}

void	setup_bench(t_bench *bench, t_config *cfg, t_stack *a)
{
	init_bench(bench, cfg);
	if (!bench->enabled)
		return ;
	bench->disorder = compute_disorder(a);
	set_bench_info(bench, cfg);
}

void	print_float(double d)
{
	int	entero;
	int	decimal;

	entero = (int)(d * 100);
	decimal = (int)(d * 10000) % 100;
	ft_putnbr_fd(entero, 2);
	ft_putchar_fd('.', 2);
	if (decimal < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(decimal, 2);
	ft_putchar_fd('%', 2);
}

void	print_bench(t_bench *bench)
{
	if (!bench || !bench->enabled)
		return ;
	ft_putstr_fd("Disorder: ", 2);
	print_float(bench->disorder);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Strategy: ", 2);
	ft_putstr_fd(bench->strategy_name, 2);
	ft_putstr_fd(" (", 2);
	ft_putstr_fd(bench->complexity, 2);
	ft_putstr_fd(")\n", 2);
	ft_putstr_fd("Total operations: ", 2);
	ft_putnbr_fd(bench->total_ops, 2);
	ft_putchar_fd('\n', 2);
	print_bench_ops_r1(bench);
	print_bench_ops_r2(bench);
}
