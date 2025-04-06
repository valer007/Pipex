/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:01:52 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/06 14:02:54 by vmakarya         ###   ########.fr       */
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

typedef struct s_pipex
{
	int		ac;
	char	**av;
	char	**ep;
	char	**path;
	int		fd1;
	int		fd2;
}	t_pipex;

void	error(void);
void	execute(char *argv, char **envp);

#endif