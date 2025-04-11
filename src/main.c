/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmakarya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 14:09:43 by vmakarya          #+#    #+#             */
/*   Updated: 2025/04/12 02:31:37 by vmakarya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc >= 5)
	{
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
