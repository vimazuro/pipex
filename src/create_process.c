/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:34:50 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 14:32:16 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	create_first_process(char **argv, int pipe_fd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_first(argv, pipe_fd, envp);
	close(pipe_fd[1]);
}

void	create_here_first_process(char **argv, int pipe_fd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_here(argv, pipe_fd, envp);
	close(pipe_fd[1]);
}

void	create_middle_process(char *argv, int prev_pipe[2], int next_pipe[2], \
char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_middle(argv, prev_pipe, next_pipe, envp);
	close(prev_pipe[0]);
	close(next_pipe[1]);
}

void	create_last_process(int argc, char **argv, int pipe_fd[2], char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		print_error("Error with fork\n");
	if (pid == 0)
		child_process_last(argc, argv, pipe_fd, envp);
	close(pipe_fd[0]);
}
