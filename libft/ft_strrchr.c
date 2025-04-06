/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 21:21:06 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/14 22:28:38 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*last_letter;

	i = 0;
	last_letter = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last_letter = (char *)&str[i];
		i++;
	}
	if (c == '\0')
		return ((char *)&str[i]);
	return (last_letter);
}
