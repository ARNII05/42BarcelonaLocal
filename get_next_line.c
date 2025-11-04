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
	size_t	i;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
static void	update_residue(char **residuo, int index)
{
	char	*tmp;

	tmp = ft_substr(*residuo, index + 1, ft_strlen(*residuo));
	free(*residuo);
	*residuo = tmp;
}
*/

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

static char	*read_file(int fd)
{
	static char			*residue;
	char				buffer[BUFFER_SIZE + 1];
	ssize_t				n;

	while (1)
	{
		if (residue && extract_index(residue, '\n') != -1)
			return (extract_line(&residue));
		n = read(fd, buffer, BUFFER_SIZE);
		if (n <= 0)
			break ;
		buffer[n] = '\0';
		residue = ft_strjoin(residue, buffer);
	}
	if (residue)
		return (extract_line(&residue));
	return (0);
}

char	*get_next_line(int fd)
{
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = read_file(fd);
	return (line);
}
