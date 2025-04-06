/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:48:16 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/23 14:35:01 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	if ((count != 0 && size >= 2147483647)
		|| (size != 0 && count >= 2147483647))
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
