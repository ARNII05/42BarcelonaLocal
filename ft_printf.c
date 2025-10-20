/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/30 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf.h"

static void choose_format(char c, va_list args)
{
	if (c == 'c' || c == '%')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	/*
	else if (c == 'p')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'd')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'i')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'u')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'x')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'X')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == '%')
		ft_putstr_fd(va_arg(args, char *), 1);
	*/
}

/*
static void write_correct_arg(int n, va_list args)
{
	if (n == 1)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (n == 2)
		ft_putstr_fd(va_arg(args, char *), 1);
}
*/

static void exctract_format(char const *format, va_list args)
{
	while (*format)
	{
		if (*format == '%')
		{
			format++; 
			if (*format)
				choose_format(*format, args);
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
}

int ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);
	exctract_format(format, args);
	va_end(args);
	return (0);
}