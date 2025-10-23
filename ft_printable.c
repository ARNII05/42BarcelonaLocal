#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("NULL"));
	while (s[i] != 0)
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	int		counter;
	char	c;

	counter = 0;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		counter += ft_putchar('-');
		counter += ft_putnbr(-n);
		return (counter);
	}
	if (n >= 10)
		counter += ft_putnbr(n / 10);
	c = (n % 10) + '0';
	counter += ft_putchar(c);
	return (counter);
}
