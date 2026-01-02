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
//Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one element or none.
void do_sa(int **stack_a, int argc)
{
	int tmp;

	if (argc < 2)
		return ;
	tmp = (*stack_a)[0];
	(*stack_a)[0] = (*stack_a)[1];
	(*stack_a)[1] = tmp;
}

// Swap the first 2 elements at the top of stack b.
//Do nothing if there is only one element or none.
void do_sb(int **stack_b, int argc)
{
	int tmp;

	if (argc < 2)
		return ;
	tmp = (*stack_b)[0];
	(*stack_b)[0] = (*stack_b)[1];
	(*stack_b)[1] = tmp;
}

//sa and sb at the same time.
void do_ss(int **stack_a, int **stack_b, int argc)
{
	do_sa(stack_a, argc);
	do_sb(stack_b, argc);
}