/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <ignmarti@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:50:24 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/11 20:18:42 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Permite strings como "++-- " (no deberia)
// Job could be done using strchr also it checks whether is a valid number
// (which) is stilll a string (previous turn into a long)...

int	valid_string_number(char *s)
{
	size_t	i;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*
// this function checks number of argc...
int	valid_input(int argc)
{
	if (argc == 1)
		return (1);
	return (0);
}*/

/* ************************************************************************** */

// This function turns an str into a long int... furthermore, it allows no more
// than either 1 '+' or 1 '-', otherwise.
long	tranform_str_to_long(const char *nptr)
{
	size_t	i;
	long	sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10 + (nptr[i] - '0'));
		i++;
	}
	return (sign * num);
}

/* ************************************************************************** */

// This function counts out number of elements from the array...

int	count_numbers(int argc, char **argv, t_config *cfg)
{
	int		count;
	int		j;
	char	**split;
	int		i;

	i = 0;
	count = 0;
	while (++i < argc)
	{
		if (flag_check(argv[i]))
			handle_flag(argv[i], cfg);
		else if (check_doble_sign(argv[i]))
			print_error();
		else
		{
			split = ft_split(argv[i], ' ');
			if (!split || !split[0])
				print_error();
			j = 0;
			while (split[j++])
				count++;
			free_split_output(split);
		}
	}
	return (count);
}

/* ************************************************************************** */

void	fill_num_array(int argc, char **argv, int *nums)
{
	int		i;
	int		k;
	char	**split;

	k = 0;
	i = 0;
	while (++i < argc)
	{
		if (!flag_check(argv[i]) && !check_doble_sign(argv[i]))
		{
			split = ft_split(argv[i], ' ');
			get_split(nums, split, &k);
		}
	}
}

/* ************************************************************************** */

void	get_split(int *nums, char **split, int *k)
{
	int		j;
	long	tmp;

	j = 0;
	while (split[j])
	{
		tmp = tranform_str_to_long(split[j]);
		if (valid_string_number(split[j]) || check_max_min(tmp))
		{
			free_split_output(split);
			free(nums);
			print_error();
		}
		nums[(*k)++] = (int)tmp;
		j++;
	}
	free_split_output(split);
}
