/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/10/21 13:00:28 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	choose_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*args, char *)));
	/*
	else if (c == 'p') 
		return (hexa_void(va_arg(*args, const void *), "0123456789ABCDEF"));
	*/
	else if (c == 'u')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789"));
	else if (c == 'X')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	else
		return (ft_putchar(c));
}

static int	exctract_format(char const *format, va_list *args)
{
	int	count_char;

	count_char = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format)
				count_char += choose_format(*format, args);
		}
		else
			count_char += ft_putchar(*format);
		format++;
	}
	return (count_char);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = exctract_format(format, &args);
	va_end(args);
	return (result);
}
