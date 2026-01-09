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
	dest[0] = src[0];
	dest->size++;
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
	}
	src->size--;
	putstr(op_name, 1);
}
