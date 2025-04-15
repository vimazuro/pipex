/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_tmp_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:14:03 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 15:25:55 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	write_tmp_file(int file_in, char *limitador)
{
	char	*line;

	while (1)
	{
		write(1, "here_doc> ", 10);
		line = get_next_line(0);
		if (!line || ft_strcmp(line, limitador) == 0)
			break ;
		write(file_in, line, ft_strlen(line));
		free(line);
	}
	if (line)
		free(line);
}
