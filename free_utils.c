/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassamoh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 12:58:41 by hassamoh          #+#    #+#             */
/*   Updated: 2026/02/09 16:14:03 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/* ************************************************************************** */

// This function's porpouse is no other than free split's output in a proper
// way. (first malloc allocated for nums, and mem for arrey which contains
// them)
void	free_split_output(char **split_output)
{
	size_t	i;

	if (!split_output)
		return ;
	i = 0;
	while (split_output[i])
	{
		free(split_output[i]);
		i++;
	}
	free(split_output);
}
