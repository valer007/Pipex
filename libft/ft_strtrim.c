/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:29:47 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/23 20:09:42 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static void	ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		len;
	char	*copy;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && check(s1[start], set))
		start++;
	while (end > start && check(s1[end - 1], set))
		end--;
	len = end - start;
	if (len == 0)
		return (ft_strdup(""));
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	ft_strncpy(copy, &s1[start], len);
	return (copy);
}
