/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:58:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 15:45:56 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	call_function(char *path, char **cmd, char **envp)
{
	execve(path, cmd, envp);
	free(path);
	free_split(cmd);
	error();
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		error();
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], X_OK) == -1)
		{
			free_split(cmd);
			error();
		}
		execve(cmd[0], cmd, envp);
	}
	path = find_path(cmd[0], envp);
	if (!path || access(path, X_OK) == -1)
	{
		free(path);
		free_split(cmd);
		error();
	}
	call_function(path, cmd, envp);
}

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
		if (argv[i][0] == '\0'
			|| (argv[i][0] == '.' && argv[i][1] != '/'))
			error();
		i++;
	}
}
