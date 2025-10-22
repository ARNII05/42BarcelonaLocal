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

static char *transform_letters(char *str, char type)
{
	char 	*new_str;
	int	i;
	
	i = 0;
	while (str[i] != 0)
	{
		if (type == 'u')
			new_str[i] = ft_toupper(new);
	}
}

static void	ft_putnbr_base(int nbr, char type)
{
	int		i;
	long	n;
	char	new_str[32];

	strlen = ft_strlen(base);
	i = 0;
	n = nbr;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n == 0)
		write(1, &base[0], 1);
	while (n > 0)
	{
		new_str[i] = base[n % strlen];
		n /= ft_strlen(base);
		i++;
	}
	while (i--)
		write(1, transform_letters(&new_str[i])[i], 1);
}

static void	nbr_no_sign(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	else if (n < 0)
	{
		ft_putnbr_fd(-n, fd);
		return ;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	ft_putchar_fd(c, fd);
}

static hexa_void(const void *s)
{
	//El puntero void * dado como argumento se imprime en formato hexadecimal.
}

static hexa_nbr(const void *s)
{
	//El puntero void * dado como argumento se imprime en formato hexadecimal.
}

static void choose_format(char c, va_list args)
{
	if (c == 'c' || c == '%')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'u')
		nbr_no_sign(va_arg(args, int), 1);
	else if (c == 'p')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'x')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'X')
		ft_putstr_fd(va_arg(args, char *), 1);
}

static int exctract_format(char const *format, va_list args)
{
	int count_char;

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
		count_char++;
	}
	return (count_char);
}

int ft_printf(char const *format, ...)
{
	va_list args;
	va_start(args, format);
	va_end(args);
	return (extract_fornat(*format, args));
}
