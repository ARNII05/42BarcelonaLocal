/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_index(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	j;
	int	size;

	max_bits = stack_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		size = stack_a->size;
		while (j < size)
		{
			if (((stack_a->data[0] >> i) & 1) == 0)
				do_p(stack_a, stack_b, "pb\n");
			else
				do_r(stack_a, "ra\n");
			j++;
		}
		while (stack_b->size > 0)
			do_p(stack_b, stack_a, "pa\n");
		i++;
	}
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	set_index(stack_a);
	sort_index(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		do_s_tasks(stack_a, "sa\n");
	else if (stack_a->size == 3)
		sort_len_three(stack_a);
	else if (stack_a->size > 3)
		sort(stack_a, stack_b);
}