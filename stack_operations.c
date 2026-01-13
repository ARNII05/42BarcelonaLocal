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

t_stack	init_stack(int capacity)
{
	t_stack	stack;

	stack.cap = capacity;
	stack.size = 0;
	stack.data = malloc(sizeof(int) * capacity);
	return (stack);
}

int stack_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	max_index;
	int i;

	max_bits = 0;
	max_index = 0;
	i = 0;
	while (i < stack_a->size)
	{
		if (max_index < stack_a->data[i])
			max_index = stack_a->data[i];
		i++;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort_len_three(t_stack *stack)
{
	int	x;
	int	y;
	int	z;

	x = stack->data[0];
	y = stack->data[1];
	z = stack->data[2];
	if (x > y && y < z && x < z)
		do_s_tasks(stack, "sa\n");
	else if (x > y && y > z)
	{
		do_s_tasks(stack, "sa\n");
		do_rrx(stack, "rra\n");
	}
	else if (x > y && y < z && x > z)
		do_r(stack, "ra\n");
	else if (x < y && y > z && x < z)
	{
		do_s_tasks(stack, "sa\n");
		do_r(stack, "ra\n");
	}
	else
		do_rrx(stack, "rra\n");
}

int	stack_is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_int(int *n, int size)
{
	int	i;
	int	j;
	int tmp;

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
