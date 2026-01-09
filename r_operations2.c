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
//Shift down all elements of any stack a by 1.
//The last element becomes the first one.
void	do_rr(t_stack *stack, char *op_name)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[stack->size - 1];
	i = stack->size - 1;
	while (i > 0)
	{
		stack->data[i] = stack->data[i - 1];
		i--;
	}
	stack->data[0] = tmp;
	if (op_name)
		putstr(op_name, 1);
}

//rra and rrb at the same time.
void	do_rrr(t_stack *stack_a, t_stack *stack_b)
{
	do_rr(stack_a, NULL);
	do_rr(stack_b, NULL);
	putstr("rrr\n", 1);
}
