/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/29 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
    size_t i;
    size_t j;
    size_t length;

    i = 0;
    length = ft_strlen(little);
    if (!*little)
        return (char *) (big);
    while (big[i] != 0 && i + length < len)
    {
        j = 0;
        while (j < length && big[i + j] == little[j])
            j++;
        if (j == length)
            return (char *)(big + i);
        i++;
    }
    return (0);
}