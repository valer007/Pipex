/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:58:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/08 23:59:13 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

void	check(int argc, char **argv, int i)
{
	while (i < argc - 1)
	{
		if (argv[i][0] == '\0' || argv[i][0] == '/' || argv[i][0] == '.')
			error();
		i++;
	}
}
