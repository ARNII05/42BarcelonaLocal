/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnau <arnau.bf05@>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:19:26 by arnau             #+#    #+#             */
/*   Updated: 2025/10/21 10:50:43 by abellavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void readFileAndJoinResidue(int fd)
{
	static char *residue;
	char buffer[BUFFER_SIZE + 1];
	ssize_t n;

	n = read(fd, buffer, BUFFER_SIZE);
}

char *get_next_line(int fd)
{
 	char *actualLine;

	readFileAndJoinResidue(fd);

	return (actualLine);
}
