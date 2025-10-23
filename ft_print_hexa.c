#include "ft_printf.h"

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

int	hexa_void(const void *s, char *base)
{
	return (0);
}