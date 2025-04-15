/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:45:23 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 15:52:53 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute_command(char *command, char **envp)
{
	char	**args;
	char	*full_path;

	args = ft_split(command, ' ');
	if (args == NULL)
		print_error("Error with memory allocation for args\n");
	if (ft_strchr(args[0], '/') != NULL)
		full_path = ft_strdup(args[0]);
	else
		full_path = find_full_path(args[0], envp);
	if (full_path == NULL)
	{
		perror("Error join path");
		exit(EXIT_FAILURE);
	}
	if (execve(full_path, args, envp) == -1)
	{
		perror("Error with input command");
		free_array(args);
		free(full_path);
		exit(EXIT_FAILURE);
	}
	free_array(args);
	free(full_path);
}
