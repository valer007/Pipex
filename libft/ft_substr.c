/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 23:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/22 00:13:04 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	max_size;
	size_t	size;
	char	*copy;
	size_t	i;

	if (!s)
		return (NULL);
	max_size = ft_strlen(s);
	if (start >= max_size)
		return (ft_strdup(""));
	size = max_size - start;
	if (size > len)
		size = len;
	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = s[start++];
		i++;
	}
	copy[size] = '\0';
	return (copy);
}
