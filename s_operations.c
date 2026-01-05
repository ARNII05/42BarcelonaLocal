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
void do_s_tasks(int **stack, int len, char *op_name)
{
	int tmp;

	if (len < 2)
		return ;
	tmp = (*stack)[0];
	(*stack)[0] = (*stack)[1];
	(*stack)[1] = tmp;
	if (!op_name)
		ft_putstr(op_name);
}

//sa and sb at the same time.
void do_ss(int **stack_a, int **stack_b, int *len, char *op_name)
{
	do_s_task(stack_a, len[0], NULL);
	do_s_task(stack_b, len[1], NULL);
	ft_putstr(op_name);
}