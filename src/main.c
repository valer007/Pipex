/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 15:47:06 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_space(int argc, char **argv)
{
	int	i;
	int	j;

	if (!ft_strncmp("here_doc", argv[1], 8))
		i = 3;
	else
		i = 2;
	while (i < argc - 1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] != 0)
				return ;
			j++;
		}
		i++;
	}
	error();
}

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
	{
		check_space(argc, argv);
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
			pipex_here_doc(argc, argv, envp);
		else
			pipex(argc, argv, envp);
	}
	else
	{
		error();
	}
	while (wait(NULL) != -1)
		;
}
