/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/12/15 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnotdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, len);
	str[len] = '\0';
	return (str);
}

char	*ft_strchr(const char *string, int c)
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