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

static int	ft_is_digit(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' && ft_strlen(str) > 1)
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] != 34) && (str[i] < 48 || str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

static int	exceeding_int(long long nbr)
{
	return (nbr > INT_MAX || nbr < INT_MIN);
}

static int	any_duplicate(int *nbr, int argc)
{
	int	i;
	int	j;

	i = 1;
	j = argc;
	while (i < j)
	{
		while (i < j)
		{
			if (nbr[i - 1] != 34 && nbr[i - 1] == nbr[j - 1])
				return (1);
			j--;
		}
		i++;
		j = argc;
	}
	return (0);
}

//Fill stack_a with user input and check if there's any errors
int	fill_stack(t_stack	*stack_a, char **argv)
{
	long long	n;
	int			i;

	i = 0;
	n = 0;
	while (i < stack_a->cap)
	{
		n = ft_atoi(argv[i]);
		if (!ft_is_digit(argv[i]) || exceeding_int(n))
			return (1);
		stack_a->data[i] = (int) n;
		stack_a->size++;
		i++;
	}
	return (any_duplicate(stack_a->data, stack_a->size));
}
