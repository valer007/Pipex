/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:47:19 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/14 23:26:11 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while ((s1[i] != 0 || s2[i] != 0) && n != 0)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] > s2[i])
				return (1);
			return (-1);
		}
		i++;
		n--;
	}
	return (0);
}
