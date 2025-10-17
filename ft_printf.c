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

#include "libft/libft.h"
#include "ft_printf.h"

static int choose_format(char c)
{
		if (c == 'c')
   return (1);
  else if (c == 's')
   return (2);
		else if (c == 'p')
   return (3);
		else if (c == 'd')
   return (4);
		else if (c == 'i')
   return (5);
		else if (c == 'u')
   return (6);
		else if (c == 'x')
   return (7);
		else if (c == 'X')
   return (8);
		else if (c == '%')
   return (9);
  else
   return (0);
}

static void write_correct_arg(int n, va_list args)
{
	if (n == 1)
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (n == 2)
		ft_putstr_fd(va_arg(args, char *), 1);
}

static void exctract_format(char const *format, va_list args)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++; 
			write_correct_arg(choose_format(*format), args);
		}
		else
			ft_putchar_fd(format, 1);
		format++;
	}
}

int ft_printf(char const *format, ...)
{
	int correct_format;
	va_list args;
	va_start(args, format);
	exctract_format(format, args);
	va_end(args);
	return 0;
}