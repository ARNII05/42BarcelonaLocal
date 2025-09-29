/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
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

char *strrchr(const char *str, int c)
{
    int len;
    int i;

    len = strlength(str);
    i = len;
    while (i >= 0)
    {
        if (c == str[i])
            return (char *)(str + i);
        i--;
    }
    return (0);
}

int main(void)
{
    printf("%s", strrchr("hola mundo", 'a'));
    printf("\n");
}