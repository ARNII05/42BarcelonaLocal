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
//Shift up all elements of stack a by 1.
//The first element becomes the last one.
void do_ra(int **stack_a)
{
	putstr("ra\n");
}


//Shift up all elements of stack b by 1.
//The first element becomes the last one
void do_rb(int **stack_b)
{
	putstr("rb\n");
}


//ra and rb at the same time
void do_rr(int **stack_a, int **stack_b)
{
do_ra(stack_a);
do_rb(stack_b);
putstr("rr\n");
}