/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:53:02 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/26 00:27:33 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*copy;
	unsigned int	j;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (!copy)
		return (NULL);
	j = 0;
	while (j < i)
	{
		copy[j] = f(j, s[j]);
		j++;
	}
	copy[i] = '\0';
	return (copy);
}
