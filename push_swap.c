/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int integer_len(int *nbrs)
{
	size_t i;
	
	i = 0;
	while (ft_strlen(ft_itoa(nbrs[i])) != 0)
		i++;
	return (i);
}

char *push_swap(int *nbrs)
{
	if (any_errors(integer_len(nbrs), nbrs))
		return ("Error\n");
	return ("");
}