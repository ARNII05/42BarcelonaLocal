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

//It makes a copy of stack_a and it orders the stack.
//The smallest at the top and the bigger at the bottom.
//Asign an index for each number comparing
//the sorted stack with the non sorted stack.
void	set_index(t_stack *stack)
{
	int	i;
	int	j;
	int	*copy;

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

//Takes each bit for each index and compares if it's 0 or 1.
//If its 0 it does pb. For number 1 ra operation.
//When it finishes one column, return all values to stack_a. 
void	sort_index(t_stack *stack_a, t_stack *stack_b)
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

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 2)
		do_s_tasks(stack_a, "sa\n");
	else if (stack_a->size == 3)
		sort_len_three(stack_a);
	else if (stack_a->size <= 5)
		sort_len_four_five(stack_a, stack_b);
	else if (stack_a->size > 5)
	{
		set_index(stack_a);
		sort_index(stack_a, stack_b);
	}
}
