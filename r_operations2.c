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
//Shift down all elements of stack a by 1.
//The last element becomes the first one.
void do_rra(int **stack_a)
{
	putstr("rra\n");
}

//Shift down all elements of stack b by 1.
//The last element becomes the first one.
void do_rrb(int **stack_b)
{
	putstr("rrb\n");
}

//rra and rrb at the same time.
void do_rrr(int **stack_a, int **stack_b)
{
	do_rra(stack_a);
	do_rrb(stack_b);
	putstr("rrr\n");
}