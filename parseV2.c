/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseV2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:49:28 by ignmarti          #+#    #+#             */
/*   Updated: 2026/02/18 16:34:51 by hassamoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function casts off an error message
void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
/* ************************************************************************** */

void	init_config(t_config *cfg)
{
	cfg->strategy = STR_UNSET;
	cfg->bench = 0;
}

/* ************************************************************************** */

int	check_doble_sign(char *s)
{
	if (s && s[0] == '-' && s[1] == '-')
		return (1);
	else if (s && s[0] == '+' && s[1] == '+')
		return (1);
	return (0);
}

/* ************************************************************************** */

// This is the comprehensive function it workds along with previous funcs...
// parse_utils1 and parse_utils2...

// 
// if no argvs, our programm musn't show anything and, subsequsing space after 
// keywoently, return
// control to user...

// Controlar entradas, con o sin flags, e inputs no validos...
// Recordar hardcodear las siguientes flaggs (Opcionales). Tener en cuenta para
// el numero de argumentos...

// En caso de error, debera! Mostrara Error seguido de un \n en la salida de 
// error standard. Algunos de los posibles errores son, por ejemplo: argumentos 
// que no son enteros, argumentos superiores a un numero entero, y/o numeros 
// duplicados.

/*
	--simple
	--medium
	--complex
	--adaptive
	--bench
*/

/* ************************************************************************** */

long	check_max_min(long num)
{
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

/* ************************************************************************** */

t_stack	*parse_arguments(int argc, char **argv, t_config *cfg)
{
	int		count;
	int		*nums;
	t_stack	*a;

	init_config(cfg);
	count = 0;
	count = count_numbers(argc, argv, cfg);
	if (count == 0)
		return (NULL);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		print_error();
	fill_num_array(argc, argv, nums);
	if (cfg->strategy == STR_UNSET)
		cfg->strategy = STR_ADAPTIVE;
	if (check_dup_nums(nums, count))
	{
		free(nums);
		print_error();
	}
	a = fill_stack(nums, count);
	free(nums);
	return (a);
}
