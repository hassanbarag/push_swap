/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <ignmarti@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:03:25 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/18 08:01:34 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function checks whether there's duplicated numbers or not as is not 
// allowed repeated numbers in this project.

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

/* ************************************************************************** */

int	check_dup_nums(int *nums, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */

// This is a function which will help us to fill our stack up!

t_stack	*fill_stack(int *nums, size_t size)
{
	t_stack	*a;
	t_stack	*new;
	size_t	i;

	a = NULL;
	i = size - 1;
	while ((int)i >= 0)
	{
		new = stack_new(nums[i]);
		stack_add_front(&a, new);
		i--;
	}
	return (a);
}

/* ************************************************************************** */

int	flag_check(char *str)
{
	if (!str)
		return (0);
	if (ft_strcmp(str, "--simple") == 0)
		return (1);
	if (ft_strcmp(str, "--medium") == 0)
		return (1);
	if (ft_strcmp(str, "--complex") == 0)
		return (1);
	if (ft_strcmp(str, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(str, "--bench") == 0)
		return (1);
	return (0);
}

/* ************************************************************************** */

void	handle_flag(char *arg, t_config *cfg)
{
	if (ft_strcmp(arg, "--bench") == 0)
	{
		if (cfg->bench)
			print_error();
		cfg->bench = 1;
	}
	else
	{
		if (cfg->strategy != STR_UNSET)
			print_error();
		if (ft_strcmp(arg, "--simple") == 0)
			cfg->strategy = STR_SIMPLE;
		else if (ft_strcmp(arg, "--medium") == 0)
			cfg->strategy = STR_MEDIUM;
		else if (ft_strcmp(arg, "--complex") == 0)
			cfg->strategy = STR_COMPLEX;
		else if (ft_strcmp(arg, "--adaptive") == 0)
			cfg->strategy = STR_ADAPTIVE;
		else
			print_error();
	}
}
