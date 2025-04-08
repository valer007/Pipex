/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:04:59 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/07 16:57:36 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i])
		{
			new_str[i] = s1[i];
			i++;
		}
		free(s1);
	}
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}

static char	*foo(char *str)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	new_str = malloc(ft_strlen(str) - i);
	if (!new_str)
		return (free(str), NULL);
	i++;
	while (str[i])
		new_str[j++] = str[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}

static char	*get_line(char *line)
{
	int		i;
	int		len;
	char	*new_line;

	i = 0;
	if (!line)
		return (NULL);
	while (line[i] && line[i] != '\n')
		i++;
	len = i + 1;
	if (line[i] == '\n')
		len++;
	new_line = malloc(sizeof(char) * len);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= len - 2)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

static char	*extract_line(char *buffer)
{
	if (!buffer || !buffer[0])
		return (NULL);
	return (get_line(buffer));
}

char	*get_next_line(int fd)
{
	static char	*str = NULL;
	char		*line;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		str = ft_strjoin_free(str, buffer);
		if (!str)
			return (NULL);
	}
	line = extract_line(str);
	str = foo(str);
	return (line);
}
