/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:28:19 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/05 21:18:48 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

static size_t	word_count(const char *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static size_t	word_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	check(const char *s, size_t words, char **result, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		result[i] = malloc(word_len(s + j, c) + 1);
		if (!result[i])
			return ;
		k = 0;
		while (s[j] && s[j] != c)
		{
			result[i][k] = s[j];
			k++;
			j++;
		}
		result[i][k] = '\0';
		i++;
	}
	result[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	words;

	if (!s)
		return (NULL);
	words = word_count(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	check(s, words, result, c);
	return (result);
}
