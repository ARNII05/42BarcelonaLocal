/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/30 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
    int	result;
	int	sign;
    int i;

	result = 0;
	sign = 1;
    i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	i++;
	if (str[i] == '-')
	sign *= -1;
	if (str[i] == '-' || str[i] == '+')
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}