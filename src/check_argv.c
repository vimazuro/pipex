/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:51:36 by vimazuro          #+#    #+#             */
/*   Updated: 2025/02/27 10:09:04 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	check_argv(int argc, char **argv)
{
	if (argc < 5)
		print_error("The input must be:\n\
./pipex file1 command1 command2 file2\n");
	if (access(argv[1], F_OK) != 0)
		ft_printf("File %s doesn't exist\n", argv[1]);
}
