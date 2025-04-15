/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:57:46 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/27 13:03:04 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	**create_pipes(int num_pipes)
{
	int	**pipe_fd;
	int	i;

	pipe_fd = malloc(num_pipes * sizeof(int *));
	if (pipe_fd == NULL)
		print_error("Error with malloc\n");
	i = 0;
	while (i < num_pipes)
	{
		pipe_fd[i] = malloc(2 * sizeof(int));
		if (pipe(pipe_fd[i]) == -1)
			print_error("Error with pipe\n");
		i++;
	}
	return (pipe_fd);
}
