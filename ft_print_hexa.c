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
	counter += ft_putchar(base[nbr % len]);
	return (counter);
}

static int	print_hex_recursive(unsigned long n, char *base)
{
	int	counter;

	counter = 0;
	if (n >= 16)
		counter += print_hex_recursive(n / 16, base);
	counter += ft_putchar(base[n % 16]);
	return (counter);
}

int	hexa_void(unsigned long *ptr, char *base)
{
	int	counter;

	counter = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	counter += ft_putstr("0x");
	return (print_hex_recursive((unsigned long)ptr, base) + counter);
}
