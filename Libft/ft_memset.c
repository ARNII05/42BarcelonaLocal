/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:31:26 by arnau             #+#    #+#             */
/*   Updated: 2025/09/30 12:31:26 by arnau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void *ft_memset(void *ptr, int value, size_t num)
{
    unsigned char *d;
	unsigned i;
	d = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		d[i] = value;
		i++;
	}
	return (d + i);
}