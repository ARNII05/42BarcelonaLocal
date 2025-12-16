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
	else if (c == 'p')
		return (hexa_void(va_arg(*args, unsigned long *), "0123456789abcdef"));
	else if (c == 'u')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789"));
	else if (c == 'X')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789ABCDEF"));
	else if (c == 'x')
		return (ft_hexa_base(va_arg(*args, unsigned int), "0123456789abcdef"));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

static char	*ft_strchr(const char *string, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(string) + 1;
	while (i < len)
	{
		if (string[i] == c)
			return ((char *)(string + i));
		i++;
	}
	return (0);
}

static int	exctract_format(char const *format, va_list *args)
{
	int	count_char;
	int	i;

	count_char = 0;
	i = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] && ft_strchr("cdispuxX%", format[i]) != 0)
				count_char += choose_format(format[i], args);
			else
			{
				count_char += choose_format('%', args);
				break ;
			}
		}
		else
			count_char += ft_putchar(format[i]);
		i++;
	}
	return (count_char);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	result = exctract_format(format, &args);
	va_end(args);
	return (result);
}
