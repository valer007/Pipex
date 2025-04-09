/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:58:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/09 17:24:18 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path_from_env(char **envp)
{
	int		i;
	char	**result;

	i = -1;
	result = NULL;
	while (envp[++i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
		{
			result = ft_split(ft_strchr(envp[i], '/'), ':');
			break ;
		}
	}
	return (result);
}

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
		if (argv[i][0] == '\0' || argv[i][0] == '/'
			|| (argv[i][0] == '.' && argv[i][1] != '/'))
			error();
		i++;
	}
}
