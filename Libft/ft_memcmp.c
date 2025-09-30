/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:50:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/30 11:50:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_memcmp(const void *ptr1, const void *ptr2, size_t count)
{
    unsigned char *a;
    unsigned char *b;
    unsigned int i;

    a = (unsigned char *)ptr1;
    b = (unsigned char *)ptr2;
    i = 0;
    while (i < count && a[i] == b[i])
        i++;
    if (i == count)
        return 0;
    return (a[i]-b[i]);
}