/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <ignmarti@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:44:31 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/12 12:50:32 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_bench_ops_r1(t_bench *bench)
{
	ft_putstr_fd("sa: ", 2);
	ft_putnbr_fd(bench->sa, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("sb: ", 2);
	ft_putnbr_fd(bench->sb, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("ss: ", 2);
	ft_putnbr_fd(bench->ss, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("pa: ", 2);
	ft_putnbr_fd(bench->pa, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("pb: ", 2);
	ft_putnbr_fd(bench->pb, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench_ops_r2(t_bench *bench)
{
	ft_putstr_fd("ra: ", 2);
	ft_putnbr_fd(bench->ra, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("rb: ", 2);
	ft_putnbr_fd(bench->rb, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("rr: ", 2);
	ft_putnbr_fd(bench->rr, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("rra: ", 2);
	ft_putnbr_fd(bench->rra, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("rrb: ", 2);
	ft_putnbr_fd(bench->rrb, 2);
	ft_putchar_fd(' ', 2);
	ft_putstr_fd("rrr: ", 2);
	ft_putnbr_fd(bench->rrr, 2);
	ft_putchar_fd('\n', 2);
}
