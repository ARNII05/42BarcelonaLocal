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


//Take the first element at the top of b and put it at the top of a.
//Do nothing if b is empty.
void do_pa(int **stack_a, int **stack_b)
{
	if (stack_b == NULL)
		return ;
	putstr("pa\n");
}

//Take the first element at the top of a and put it at the top of b.
//Do nothing if a is empty.
void do_pb(int **stack_a, int **stack_b)
{
	if (stack_a == NULL)
		return ;
	putstr("pb\n");
}