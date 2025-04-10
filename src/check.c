/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:58:54 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/10 13:28:37 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
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
		if (argv[i][0] == '\0' || argv[i][0] == '/'
			|| (argv[i][0] == '.' && argv[i][1] != '/'))
			error();
		i++;
	}
}

int	open_file(char *argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}
