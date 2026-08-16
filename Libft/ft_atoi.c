/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ignmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 11:50:33 by ignmarti          #+#    #+#             */
/*   Updated: 2026/01/08 11:50:58 by ignmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
DESCRIPTION
       The atoi() function converts the initial portion
       of the string pointed to by nptr to int.  The
       behavior is the same as

           strtol(nptr, NULL, 10);

       except that atoi() does not detect errors.

       The atol() and atoll() functions behave the same as
       atoi(), except that they convert the  ini‐
       tial portion of the string to their return type of
       long or long long.✅️

RETURN VALUE
       The converted value or 0 on error.✅️
*/
int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		if (!(nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
			return (0);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = (num * 10 + (nptr[i] - '0'));
		i++;
	}
	return (sign * num);
}
/*
int	main(void)
{
	int	num1;
	int	num2;

	num1 = ft_atoi("   			   +-125ffdf");
	num2 = atoi("     				 +125ffdf");
	printf("%d\n", num1);
	printf("%d\n", num2);
	return (0);
}*/
