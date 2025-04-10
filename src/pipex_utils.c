/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:14:13 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/10 13:29:45 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*search_in_path(char *argv, char **paths)
{
	int		i;
	char	*temp;
	char	*full_path;

	i = -1;
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, argv);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_split(paths);
			return (full_path);
		}
		free(full_path);
	}
	free_split(paths);
	return (NULL);
}

char	*find_path(char *argv, char **envp)
{
	char	**paths;

	if ((argv[0] == '.' && argv[1] == '/') || (argv[0] == '.'
			&& argv[1] == '.' && argv[2] == '/'))
	{
		if (access(argv, F_OK | X_OK) == 0)
			return (ft_strdup(argv));
		return (NULL);
	}
	paths = get_path_from_env(envp);
	if (!paths)
		return (NULL);
	return (search_in_path(argv, paths));
}

static int	get_line(char **line)
{
	char	*buffer;
	int		i;
	int		r;
	char	c;

	i = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	r = read(0, &c, 1);
	while (r > 0 && c != '\n')
	{
		buffer[i++] = c;
		r = read(0, &c, 1);
	}
	if (r <= 0 && i == 0)
	{
		free(buffer);
		return (0);
	}
	buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	return (1);
}

void	helper(pid_t pid, int *fd, char *line, char *limiter)
{
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			write(1, "heredoc> ", 9);
			if (get_line(&line) <= 0)
				break ;
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
				&& ft_strlen(line) == ft_strlen(limiter) + 1)
			{
				free(line);
				break ;
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
}

void	here_doc(char *limiter, int argc)
{
	pid_t	pid;
	int		fd[2];
	char	*line;

	line = NULL;
	if (argc < 6 || pipe(fd) == -1)
		error();
	pid = fork();
	if (pid < 0)
		error();
	helper(pid, fd, line, limiter);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	wait(NULL);
}
