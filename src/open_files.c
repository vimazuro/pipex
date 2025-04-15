/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:12:25 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 14:47:14 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_input_file(char *input_file)
{
	int	file_in;

	file_in = open(input_file, O_RDONLY);
	if (file_in == -1)
		print_error("Error with input file\n");
	return (file_in);
}

int	open_output_file(char *output_file)
{
	int	file_out;

	file_out = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_out == -1)
		print_error("Error with output file\n");
	return (file_out);
}

int	open_tmp_file(char *tmp_file)
{
	int	file_tmp;

	file_tmp = open(tmp_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_tmp == -1)
		print_error("Error with tmp file\n");
	return (file_tmp);
}
