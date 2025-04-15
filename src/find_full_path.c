/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_full_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:20:00 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/26 15:13:16 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_env_value(const char *name, char **envp)
{
	int		i;
	size_t	len;

	if (!name || !envp)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

static char	**get_paths(char **envp)
{
	char	*all_path;
	char	**paths;

	all_path = get_env_value("PATH", envp);
	if (!all_path)
		print_error("Error: PATH not found\n");
	paths = ft_split(all_path, ':');
	if (!paths)
		print_error("Error with memory allocation for paths\n");
	return (paths);
}

char	*find_full_path(const char *command, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*tmp;

	paths = get_paths(envp);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, command);
		free(tmp);
		if (access(full_path, F_OK) == 0)
		{
			free_array(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_array(paths);
	return (NULL);
}
