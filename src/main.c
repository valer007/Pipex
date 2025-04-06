/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/06 14:10:45 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	parent_process(char **argv, char **envp, int *fd)
{
	int	out;

	out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (out == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(out, STDOUT_FILENO);
	close(fd[1]);
	execute(argv[3], envp);
}

static void	child_process(char **argv, char **envp, int *fd)
{
	int	in;

	in = open(argv[1], O_RDONLY, 0777);
	if (in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(in, STDIN_FILENO);
	close(fd[0]);
	execute(argv[2], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid1 = fork();
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
		write(1, "Error arguments", 15);
	return (0);
}
