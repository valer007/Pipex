/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 02:19:21 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 02:35:11 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

static void	last_commad(char **argv, int argc, char **envp, t_pip pip)
{
	pip.pid = fork();
	if (pip.pid == -1)
		error();
	if (pip.pid == 0)
	{
		dup2(pip.prev_fd, STDIN_FILENO);
		dup2(pip.output, STDOUT_FILENO);
		close(pip.prev_fd);
		close(pip.output);
		execute(argv[argc - 2], envp);
	}
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

void	pipex(int argc, char **argv, char **envp)
{
	t_pip	pip;

	pip = helper2(argv, argc);
	pip.prev_fd = pip.input;
	while (pip.i < argc - 2)
	{
		pip.pid = fork();
		if (pipe(pip.fd) == -1 || pip.pid == -1)
			error();
		if (pip.pid == 0)
		{
			dup2(pip.prev_fd, STDIN_FILENO);
			dup2(pip.fd[1], STDOUT_FILENO);
			close(pip.fd[0]);
			close(pip.fd[1]);
			close(pip.prev_fd);
			execute(argv[pip.i], envp);
		}
		close(pip.fd[1]);
		close(pip.prev_fd);
		pip.prev_fd = pip.fd[0];
		pip.i++;
	}
	last_commad(argv, argc, envp, pip);
	close(pip.prev_fd);
	close(pip.output);
}
