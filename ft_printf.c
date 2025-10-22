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

#include "Libft/libft.h"
#include "ft_printf.h"

static int ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int len;
	int counter;

	len = ft_strlen(base);
	counter = 0;
	if (nbr >= len)
		counter += ft_putnbr_base(nbr / len, base);
	write(1, &base[nbr % len], 1);
	counter++;
	return (counter);
}

static int hexa_void(const void *s)
{
	//El puntero void * dado como argumento se imprime en formato hexadecimal.
}

static int	ft_putchar(char c)
{
		write(1, &c, 1);
		return (1);
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

static int ft_putnbr(int n)
{
	int counter;
	char c;

	counter = 0;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putstr("2147483648");
		return (11); 
	}
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
		return counter;
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	counter += ft_putchar(c);

	return (counter);
}

static int choose_format(char c, va_list *args)
{
	if (c == 'c' || c == '%')
		return ft_putchar(va_arg(*args, int));
	else if (c == 'd' || c == 'i')
		return ft_putnbr(va_arg(*args, int));
	else if (c == 's')
		return ft_putstr(va_arg(*args, char *));
	else if (c == 'p') //Not done 
		return ft_putstr(va_arg(*args, char *));
	else if (c == 'u')
		return ft_putnbr_base(va_arg(*args, int), "0123456789");
	else if (c == 'x')
		return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789ABCDEF");
	else if (c == 'X')
		return ft_putnbr_base(va_arg(*args, unsigned int), "0123456789abcdef");
}

static int exctract_format(char const *format, va_list *args)
{
	int count_char;

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
		{
			ft_putchar_fd(*format, 1);
			count_char++;
		}
		format++;
	}
	return (count_char);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = extract_format(format, &args);
	va_end(args);
	return (result);
}
