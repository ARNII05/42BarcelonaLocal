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

static int	errors_stack(t_stack	*stack_a, char **argv)
{
	int		i;
	long	n;

	i = 1;
	n = 0;
	while (i < stack_a->data)
	{
		n = ft_atoi(argv[i]);
		if (!ft_is_digit(argv[i]) || exceeding_int(n))
		{
			free(stack_a->data);
			return (stack_a->data = NULL, putstr("Error\n", 2), 0);
		}
		stack_a->data[i - 1] = (int) n;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		error;

	if (argc < 2)
		return (0);
	stack_a = init_stack(argc - 1);
	stack_b = init_stack(argc - 1);
	if (!stack_a.data || !stack_b.data)
		return (0);
	error = errors_stack(&stack_a, argv);
	if (any_duplicate(stack_a.data, stack_a.size) || error)
	{
		free(stack_a.data);
		return (free(stack_b.data), putstr("Error\n", 2), 0);
	}
	push_swap(&stack_a, &stack_b);
	return (free(stack_a.data), free(stack_b.data), 1);
}
