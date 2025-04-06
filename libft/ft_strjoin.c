/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:14:19 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/22 00:25:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*chlp(char const *s1, char const *s2, char *copy)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		copy[i] = s2[j];
		i++;
		j++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*copy;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	copy = malloc(s1_size + s2_size + 1);
	if (!copy)
		return (NULL);
	copy = chlp(s1, s2, copy);
	return (copy);
}
