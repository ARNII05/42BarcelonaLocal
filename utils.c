/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	result;
	int			sign;
	int			i;

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

int	*copy_int(int cap, int *n)
{
	int	*c;
	int	i;

	i = 0;
	c = malloc(sizeof(int) * cap);
	if (!c)
		return (NULL);
	while (i < cap)
	{
		c[i] = n[i];
		i++;
	}
	return (c);
}

int	lowest_n(int *data, int size)
{
	int	i;
	int	lowest;

	if (size <= 0)
		return (0);
	lowest = 0;
	i = 1;
	while (i < size)
	{
		if (data[i] < data[lowest])
			lowest = i;
		i++;
	}
	return (lowest);
}

void	sort_int(int *n, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (n[i] > n[j])
			{
				tmp = n[i];
				n[i] = n[j];
				n[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	bring_min_to_top(t_stack *stack)
{
	int	min_i;
	int	moves;

	min_i = lowest_n(stack->data, stack->size);
	if (min_i <= stack->size / 2)
	{
		while (min_i-- > 0)
			do_r(stack, "ra\n");
	}
	else
	{
		moves = stack->size - min_i;
		while (min_i++ < stack->size)
			do_rrx(stack, "rra\n");
	}
}
