/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Take the first element at the top of src and put it at the top of dest
void	do_p(t_stack *src, t_stack *dest, char *op_name)
{
	int	i;

	if (src->size == 0)
		return ;
	i = dest->size;
	while (i > 0)
	{
		dest->data[i] = dest->data[i - 1];
		i--;
	}
	dest->data[0] = src->data[0];
	dest->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
	putstr(op_name, 1);
}

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

//Shift down all elements of any stack a by 1.
//The last element becomes the first one.
void	do_rrx(t_stack *stack, char *op_name)
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
		putstr(op_name, 1);
}
