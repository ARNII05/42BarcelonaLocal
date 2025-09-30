/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/30 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int strlen(unsigned char *c)
{
    unsigned int i;

    i = 0;
    while(c[i] != 0)
        i++;
    return (i);
}

void    *ft_memchr(const void* ptr, int ch, size_t count)
{
    unsigned char *a;
    unsigned int i;

    a = (unsigned char *)ptr;
    i = 0;
    while (i < strlen(a) + 1 && i < count)
    {
        if (a[i] == ch)
            return (a + i);
        i++;
    }
    return (0);
}