/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:14:13 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/06 14:21:27 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		free(arr[i++]);
	free(arr);
}

static char	**get_path_from_env(char **envp)
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

static char	*find_path(char *argv, char **envp)
{
	int		i;
	char	**result;
	char	*full_path;
	char	*temp;

	result = get_path_from_env(envp);
	if (!result)
		return (NULL);
	i = -1;
	while (result[++i])
	{
		temp = ft_strjoin(result[i], "/");
		full_path = ft_strjoin(temp, argv);
		free(temp);
		if (access(full_path, F_OK) == 0)
		{
			free_split(result);
			return (full_path);
		}
		free(full_path);
	}
	free_split(result);
	return (NULL);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free(path);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_split(cmd);
		error();
	}
	free(path);
	free_split(cmd);	
}
