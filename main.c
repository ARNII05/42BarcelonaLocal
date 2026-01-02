/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	stack_a = malloc(sizeof(int) * (argc - 1));
	if (!stack_a)
		return (0);
	while (i < argc)
	{
		if (!ft_is_digit(argv[i]))
			return (putstr("Error\n"), 0);
		stack_a[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (any_errors(stack_a, argc))
		return (putstr("Error\n"), 0);
	return (push_swap(&stack_a, argc - 1), free(stack_a), 0);
}
