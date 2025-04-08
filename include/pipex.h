/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:01:52 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/08 23:39:54 by vmakarya         ###   ########.fr       */
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
	int	i;
	int	input;
	int	output;
}				t_pip;

void	here_doc_check(char *line, char *limiter, int *fd);
void	error(void);
void	execute(char *argv, char **envp);
void	here_doc(char *argv, int argc);
void	free_split(char **arr);
char	*find_path(char *argv, char **envp);
void	check(int argc, char **argv, int i);
void	free_split(char **arr);

#endif