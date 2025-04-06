/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:42:18 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/13 21:51:03 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		src_size;
	const char	*s;
	char		*dst1;
	const char	*src1;

	s = src;
	src_size = 0;
	while (*s++)
	{
		src_size++;
	}
	if (dstsize > 0)
	{
		dst1 = dst;
		src1 = src;
		while (dstsize > 1 && *src1)
		{
			*dst1++ = *src1++;
			dstsize--;
		}
		*dst1 = '\0';
	}
	return (src_size);
}
