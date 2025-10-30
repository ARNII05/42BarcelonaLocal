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

static unsigned int	extractIndex(const char *string, int c)
{
	unsigned int	len;
	int	i;

	i = 0;
	len = ft_strlen(string) + 1;
	while (i < len)
	{
		if (string[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	update_residue(char **residuo, int index)
{
	char	*tmp;

	tmp = ft_substr(*residuo, index + 1, ft_strlen(*residuo));
	free(*residuo);
	*residuo = tmp;
}

char *extractLine(char **residue)
{
	int index;
	char *line;
	
	index = extractIndex(*residue, '\n');
	if (index >= 0)
	{
		line = ft_substr(*residue, 0, index + 1);
		update_residue(residue, index);
	}
	else
	{
		line = ft_strdup(*residue);
		free(*residue);
		*residue = NULL;
	}
	return (line);
}

static char	*readFile(int fd)
{
	char buffer[BUFFER_SIZE + 1];
	static char *residue;
	ssize_t n;
	char *line;

	while (1)
	{
		if (residue && extractIndex(residue, '\n') != -1)
			return (extractLine(&residue));
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break;
		buffer[n] = '\0';
		residue = ft_strjoin(residue, buffer);
	}
	if (residue)
  return extract_line(&residue);
 return NULL;
}

char	*get_next_line(int fd) 
{
 	char *actualLine;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	actualLine = readFile(fd);
	return (actualLine);
}
