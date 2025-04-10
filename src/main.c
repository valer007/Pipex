/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/10 13:30:23 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

t_pip	helper1(char **argv, int argc)
{
	t_pip	pip;

	pip.i = 3;
	pip.output = open_file(argv[argc - 1], 0);
	here_doc(argv[2], argc);
	check(argc, argv, pip.i);
	return (pip);
}

t_pip	helper2(char **argv, int argc)
{
	t_pip	pip;

	pip.i = 2;
	pip.output = open_file(argv[argc - 1], 1);
	pip.input = open_file(argv[1], 2);
	dup2(pip.input, STDIN_FILENO);
	check(argc, argv, pip.i);
	return (pip);
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
	}
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	last_pid;
	t_pip	pip;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			pip = helper1(argv, argc);
		else
		{
			pip = helper2(argv, argc);
		}
		while (pip.i < argc - 2)
			child_process(argv[pip.i++], envp);
		last_pid = fork();
		if (last_pid == 0)
		{
			if (dup2(pip.output, STDOUT_FILENO) == -1)
				error();
			close(pip.output);
			execute(argv[argc - 2], envp);
		}
		close(pip.output);
	}
	while (wait(NULL) != -1)
		;
}
