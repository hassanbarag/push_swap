/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:25:30 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/18 14:29:02 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "./Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef enum e_strategy
{
	STR_UNSET,
	STR_SIMPLE,
	STR_MEDIUM,
	STR_COMPLEX,
	STR_ADAPTIVE
}	t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	int			bench;
}	t_config;

typedef struct s_bench
{
	int			enabled;
	long		sa;
	long		sb;
	long		ss;
	long		pa;
	long		pb;
	long		ra;
	long		rb;
	long		rr;
	long		rra;
	long		rrb;
	long		rrr;
	long		total_ops;
	double		disorder;
	char		*strategy_name;
	char		*complexity;
}	t_bench;

typedef struct s_range
{
	int	min;
	int	max;
}	t_range;

// stack.c
t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new_item);
void	stack_add_front(t_stack **stack, t_stack *new_item);
int		stack_size(t_stack *stack);

// swap.c
void	swap(t_stack **stack);
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);

// push.c
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **a, t_stack **b, t_bench *bench);

// rotate.c
void	rotate(t_stack **stack);
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);

// reverse_rotate.c
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

// utils.c
int		find_min(t_stack *a);
int		find_max(t_stack *a);
int		find_position(t_stack *a, int value);
int		is_sorted(t_stack *a);

// parseV2.c
void	print_error(void);
void	init_config(t_config *cfg);
int		check_doble_sign(char *s);
long	check_max_min(long num);
t_stack	*parse_arguments(int argc, char **argv, t_config *cfg);

// parse_utils1.c
int		valid_string_number(char *s);
long	tranform_str_to_long(const char *nptr);
int		count_numbers(int argc, char **argv, t_config *cfg);
void	fill_num_array(int argc, char **argv, int *nums);
void	get_split(int *nums, char **split, int *k);

// parse_utils2.c

int		check_dup_nums(int *nums, size_t size);
t_stack	*fill_stack(int *nums, size_t size);
int		flag_check(char *str);
void	handle_flag(char *arg, t_config *cfg);
void	init_config(t_config *cfg);

// disorder.c
double	compute_disorder(t_stack *a);

// sort_small.c
void	sort_small(t_stack **a, t_stack **b, t_bench *bench);
void	sort_2(t_stack **a, t_bench *bench);
void	sort_3(t_stack **a, t_bench *bench);
void	sort_4(t_stack **a, t_stack **b, t_bench *bench);
void	sort_5(t_stack **a, t_stack **b, t_bench *bench);

// simple_algo.c
void	simple_min_max(t_stack **a, t_stack **b, t_bench *bench);

// medium_algo.c
void	chunk_based_sorting(t_stack **a, t_stack **b, t_bench *bench);
void	push_chunk_to_b(t_stack **a,
			t_stack **b,
			t_range range,
			t_bench *bench);
void	push_back_to_a(t_stack **a, t_stack **b, t_bench *bench);
void	process_chunks(t_stack **a);

// medium_helper.c
int		ft_sqrt(int size);
int		find_pos_in_range(t_stack *a, int min, int max);
int		find_max_index(t_stack *b);
void	rotate_to_top_a(t_stack **a, int pos, t_bench *bench);
void	rotate_to_top_b(t_stack **a, int pos, t_bench *bench);

// complex_algo.c
void	complex_algo(t_stack **a, t_stack **b, t_bench *bench);
void	radix_lsd(t_stack **a, t_stack **b, t_bench *bench);
int		max_index_bits(t_stack *a);

// complex_helper.c
void	fill_array(t_stack *a, int *arr);
void	sort_array(int *arr, int size);
void	assign_index(t_stack *a, int *arr, int size);
void	index_stack(t_stack *a);

// free_utils.c
void	free_stack(t_stack **stack);
void	free_split_output(char **split_output);

// adaptive.c
void	adaptive_sort(t_stack **a, t_stack **b, t_bench *bench);
void	adaptive_sort_simple(t_stack **a, t_stack **b, t_bench *bench);
void	adaptive_sort_medium(t_stack **a, t_stack **b, t_bench *bench);
void	adaptive_sort_complex(t_stack **a, t_stack **b, t_bench *bench);

// bench.c
void	init_bench(t_bench *bench, t_config *cfg);
void	print_float(double d);
void	print_bench(t_bench *bench);
void	set_bench_info(t_bench *bench, t_config *cfg);
void	setup_bench(t_bench *bench, t_config *cfg, t_stack *a);

// bench_utils.c
void	print_bench_ops_r1(t_bench *bench);
void	print_bench_ops_r2(t_bench *bench);

#endif
