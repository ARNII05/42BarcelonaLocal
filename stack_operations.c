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

void sort_len_three(t_stack *stack)
{

}

void sort(t_stack *stack_a, t_stack *stack_b)
{

}

int stack_is_sorted(t_stack *stack)
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
