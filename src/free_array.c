/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:26:04 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/27 12:47:38 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_pipe_array(int **pipe_fd, int num_pipes)
{
	int	i;

	if (!pipe_fd)
		return ;
	i = 0;
	while (i < num_pipes)
	{
		free(pipe_fd[i]);
		i++;
	}
	free(pipe_fd);
}
