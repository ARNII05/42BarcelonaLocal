/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
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

//It checks how many bits you need for the biggest index.
int	stack_max_bits(t_stack *stack_a)
{
	int	max_bits;
	int	max_index;
	int	i;

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

void	sort_len_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	nbr_moves;
	int	i;

	if (stack_a->size == 4)
		nbr_moves = 1;
	else
		nbr_moves = 2;
	i = nbr_moves;
	while (i > 0)
	{
		bring_min_to_top(stack_a);
		do_p(stack_a, stack_b, "pb\n");
		i--;
	}
	sort_len_three(stack_a);
	while (nbr_moves > 0)
	{
		do_p(stack_b, stack_a, "pa\n");
		nbr_moves--;
	}
}

//It does all the combinations for a len of 3 (harcoded).
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
	else if (!stack_is_sorted(stack))
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
