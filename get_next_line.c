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

static int	extract_index(const char *str, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str) + 1;
	while (i < len)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}

static char	*extract_line(char **residue)
{
	int		index;
	char	*line;
	char	*tmp;

	index = extract_index(*residue, '\n');
	if (index >= 0)
	{
		line = ft_substr(*residue, 0, index + 1);
		tmp = ft_substr(*residue, index + 1, ft_strlen(*residue));
		free(*residue);
		*residue = tmp;
	}
	else
	{
		line = ft_strdup(*residue);
		free(*residue);
		*residue = NULL;
	}
	return (line);
}

char	*read_file(int fd, char **residue)
{
	ssize_t	n;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(buffer), NULL);
	while (1)
	{
		if (extract_index(*residue, '\n') != -1)
			return (free(buffer), extract_line(residue));
		n = read(fd, buffer, BUFFER_SIZE);
		if (n < 0)
			return (free(buffer), free(*residue), *residue = NULL, NULL);
		if (n == 0)
			break ;
		buffer[n] = '\0';
		*residue = ft_strjoin(*residue, buffer);
		if (!*residue)
			return (free(buffer), free(*residue), *residue = NULL, NULL);
	}
	free(buffer);
	if (*residue && **residue)
		return (extract_line(residue));
	return (free(*residue), *residue = NULL, NULL);
}

char	*get_next_line(int fd)
{
	static char	*residue;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(residue), residue = NULL, NULL);
	if (!residue)
	{
		residue = ft_strdup("");
		if (!residue)
			return (NULL);
	}
	return (read_file(fd, &residue));
}
