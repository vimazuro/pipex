/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:15:38 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 14:29:22 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	process_two_commands(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		print_error("Error with pipe\n");
	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_first(argv, pipe_fd, envp);
	close(pipe_fd[1]);
	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_last(argc, argv, pipe_fd, envp);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
}

void	process_mult_commands(int argc, char **argv, char **envp)
{
	int		i;
	int		num_pipes;
	int		**pipe_fd;

	num_pipes = argc - 4;
	pipe_fd = create_pipes(num_pipes);
	create_first_process(argv, pipe_fd[0], envp);
	i = 1;
	while (i < num_pipes)
	{
		create_middle_process(argv[i + 2], pipe_fd[i - 1], pipe_fd[i], envp);
		i++;
	}
	create_last_process(argc, argv, pipe_fd[num_pipes - 1], envp);
	i = 0;
	while (i <= num_pipes)
	{
		wait(NULL);
		i++;
	}
	free_pipe_array(pipe_fd, num_pipes);
}

void	process_here_commands(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		print_error("Error with pipe\n");
	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_here(argv, pipe_fd, envp);
	close(pipe_fd[1]);
	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_last(argc, argv, pipe_fd, envp);
	close(pipe_fd[0]);
	wait(NULL);
	wait(NULL);
}

void	process_here_mult_commands(int argc, char **argv, char **envp)
{
	int		i;
	int		num_pipes;
	int		**pipe_fd;

	num_pipes = argc - 5;
	pipe_fd = create_pipes(num_pipes);
	create_here_first_process(argv, pipe_fd[0], envp);
	i = 1;
	while (i < num_pipes)
	{
		create_middle_process(argv[i + 3], pipe_fd[i - 1], pipe_fd[i], envp);
		i++;
	}
	create_last_process(argc, argv, pipe_fd[num_pipes - 1], envp);
	i = 0;
	while (i <= num_pipes)
	{
		wait(NULL);
		i++;
	}
	free_pipe_array(pipe_fd, num_pipes);
}
