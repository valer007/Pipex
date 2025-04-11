/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:01:52 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 02:17:45 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include "libft.h"
# include <fcntl.h>

typedef struct s_pip
{
	int		i;
	int		fd[2];
	int		input;
	int		output;
	int		prev_fd;
	pid_t	pid;
}				t_pip;

void	error(void);
void	execute(char *argv, char **envp);
void	here_doc(char *argv, int argc);
void	free_split(char **arr);
char	*find_path(char *argv, char **envp);
void	check(int argc, char **argv, int i);
void	free_split(char **arr);
char	**get_path_from_env(char **envp);
int		open_file(char *argv, int i);
void	execute(char *argv, char **envp);
t_pip	helper1(char **argv, int argc);
t_pip	helper2(char **argv, int argc);
void	pipex(int argc, char **argv, char **envp);
void	pipex_here_doc(int argc, char **argv, char **envp);
#endif