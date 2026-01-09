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
//Shift up all elements of any stack by 1.
//The first element becomes the last one.
void	do_r(t_stack *stack, char *op_name)
{
	int	tmp;
	int	i;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	i = 0;
	while (i < stack->size - 1)
	{
		stack->data[i] = stack->data[i + 1];
		i++;
	}
	stack->data[stack->size - 1] = tmp;
	if (op_name)
		putstr(op_name, 1);
}

//ra and rb at the same time
void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	do_r(stack_a, NULL);
	do_r(stack_b, NULL);
	putstr("rr\n", 1);
}
