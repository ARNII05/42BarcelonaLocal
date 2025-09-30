/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/29 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *string, int c)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(string) + 1;
    while (i < len)
    {
        if (string[i] == c)
            return (char *) (string + i);
        i++;
    }
    return (0);
}