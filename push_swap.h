/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/10/21 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_hexa_base(unsigned int nbr, char *base);
int	hexa_void(unsigned long *ptr, char *base);

#endif
