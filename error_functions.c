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

static int	ft_isnotdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

static int exceeding_int(long nbr)
{
	return (nbr > 2147483647 || nbr < -2147483648);
}

static int is_duplicate(int *nbr)
{

}

int any_errors(int nbr)
{
	return (ft_isnotdigit(nbr) || exceeding_int(nbr));
}