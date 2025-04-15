/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:18:45 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 14:46:27 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc == 6)
			process_here_commands(argc, argv, envp);
		else if (argc > 6)
			process_here_mult_commands(argc, argv, envp);
		else
			print_error("The input must be:\n\
./pipex here_doc LIMITADOR file1 command1 command2 file2\n");
		return (EXIT_SUCCESS);
	}
	else
	{
		check_argv(argc, argv);
		if (argc == 5)
			process_two_commands(argc, argv, envp);
		else if (argc > 5)
			process_mult_commands(argc, argv, envp);
		else
			print_error("The input must be:\n\
./pipex file1 command1 command2 file2\n");
		return (EXIT_SUCCESS);
	}
}
