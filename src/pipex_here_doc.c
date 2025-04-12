/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:27:19 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 12:02:03 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_pip	helper1(char **argv, int argc)
{
	t_pip	pip;

	pip.i = 3;
	pip.output = open_file(argv[argc - 1], 0);
	here_doc(argv[2], argc);
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

void	pipex_here_doc(int argc, char **argv, char **envp)
{
	t_pip	pip;
	pid_t	last_pid;

	pip = helper1(argv, argc);
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
