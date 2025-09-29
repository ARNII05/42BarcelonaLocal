/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/29 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int strlength(const char *c)
{
    int i;

    i = 0;
    while(c[i] != 0)
        i++;
    return (i);
}

void *ft_memmove(void *dest, const void *src, unsigned int n)
{
    unsigned char *d;
    unsigned char *s;
    unsigned int i;
    int a;

    s = (unsigned char *)src;
    d = (unsigned char *)dest;
    i = 0;
    a = n - 1;
    if (d == s || n == 0)
        return dest;
    if (d < s)
    {
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    else
    {
        while (a >= 0)
        {
            d[a] = s[a];
            a--;
        }
    }

    return dest;
}

int main() {z
    char str[20] = "Hola mundo";

    char *res = ft_memmove(str + 5, str, 4); 

    printf("str: %s\n", str);
    printf("res apunta a: %s\n", res); 
    return 0;
}