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

long	ft_atoi(const char *str)
{
	long	result;
	long	sign;
	int		i;

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

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != 0)
		i++;
	return (i);
}

static int *copy_int(int cap, int *n)
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

void	set_index(t_stack *stack)
{
	int	i;
	int	j;
	int *copy;

	i = 0;
	copy = copy_int(stack->cap, stack->data);
	sort_int(copy, stack->size);
	while (i < stack->size)
	{
		j = 0;
		while (j < stack->size)
		{
			if (stack->data[i] == copy[j])
			{
				stack->data[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(copy);
}
