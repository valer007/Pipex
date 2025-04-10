/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/10 11:23:33 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
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

static void	child_process(char *argv, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error();
		execute(argv, envp);
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error();
		close(fd[0]);
		// waitpid(pid, NULL, 0);
	}
}



int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			pip.i = 3;
			pip.output = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
			check(argc, argv, pip.i);
		}
		else
		{
			pip.i = 2;
			pip.output = open_file(argv[argc - 1], 1);
			pip.input = open_file(argv[1], 2);
			dup2(pip.input, STDIN_FILENO);
			check(argc, argv, pip.i);
		}
		while (pip.i < argc - 2)
			child_process(argv[pip.i++], envp);
		dup2(pip.output, STDOUT_FILENO);
		execute(argv[argc - 2], envp);
	}
	while (wait(NULL) > 0)
		;
	return (0);
}
