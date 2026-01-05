/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_digit(char	*str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	exceeding_int(long nbr)
{
	return (nbr > 2147483647 || nbr < -2147483648);
}

int	any_duplicate(int *nbr, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = argc;
	while (i < j)
	{
		while (i < j)
		{
			if (nbr[i - 1] == nbr[j - 1])
				return (1);
			j--;
		}
		i++;
		j = argc;
	}
	return (0);
}