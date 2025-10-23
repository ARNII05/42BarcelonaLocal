/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/10/21 13:00:28 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"

int	ft_hexa_base(unsigned int nbr, char *base)
{
	unsigned int	len;
	int				counter;

	len = ft_strlen(base);
	counter = 0;
	if (nbr >= len)
		counter += ft_hexa_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
	counter++;
	return (counter);
}

/*
int	hexa_void(const void *s, char *base)
{
	return (0);
}
*/