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

#include <stdio.h>

int strlen(char *c)
{
    int i;

    i = 0;
    while(c[i] != 0)
        i++;
    return (i);
}

char *ft_strnstr(char *big, char *little, int len)
{
    int i;
    int j;
    int length;
    int count;

    i = 0;
    length = strlen(little);
    if (!*little)
        return (big);
    while (big[i] != 0 && i < len)
    {
        j = 0;
        count = 0;
        while (big[i + j] != 0 && little[j] != 0)
        {
            if (big[i + j] == little[j])
                count++;
            j++;
        }
        if (count == length)
            return (&big[i]);
        i++;
    }
    return (0);
}