/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:18:42 by vmakarya          #+#    #+#             */
/*   Updated: 2025/01/24 02:51:04 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ch;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = check_sign(n);
	ch = malloc((len + 1) * sizeof(char));
	if (!ch)
		return (NULL);
	ch[len] = '\0';
	if (n < 0)
	{
		ch[0] = '-';
		n = -n;
	}
	if (n == 0)
		ch[0] = '0';
	while (n > 0)
	{
		ch[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (ch);
}
