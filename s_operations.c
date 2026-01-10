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

//Swap the first 2 elements at the top of any stack.
//Do nothing if there is only one element or none.
void	do_s_tasks(t_stack *stack, char *op_name)
{
	int	tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = tmp;
	if (op_name)
		ft_putstr(op_name);
}

//sa and sb at the same time.
void	do_ss(t_stack *stack_a, t_stack *stack_b)
{
	do_s_task(stack_a, NULL);
	do_s_task(stack_b, NULL);
	ft_putstr("ss\n");
}
