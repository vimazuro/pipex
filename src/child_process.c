/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:01:31 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 15:18:37 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process_first(char **argv, int pipe_fd[2], char **envp)
{
	int		file_in;

	file_in = open_input_file(argv[1]);
	dup2(file_in, STDIN_FILENO);
	close(file_in);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(argv[2], envp);
}

void	child_process_last(int argc, char **argv, int pipe_fd[2], char **envp)
{
	int	file_out;

	file_out = open_output_file(argv[argc - 1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	execute_command(argv[argc - 2], envp);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(file_out);
}

void	child_process_middle(char *argv, int prev_pipe[2], int next_pipe[2], \
char **envp)
{
	dup2(prev_pipe[0], STDIN_FILENO);
	close(prev_pipe[0]);
	dup2(next_pipe[1], STDOUT_FILENO);
	close(prev_pipe[1]);
	close(next_pipe[0]);
	close(next_pipe[1]);
	execute_command(argv, envp);
}

void	child_process_here(char **argv, int pipe_fd[2], char **envp)
{
	int		file_in;
	char	*limitador;

	file_in = open_tmp_file(".here_doc_tmp");
	limitador = ft_strjoin(argv[2], "\n");
	write_tmp_file(file_in, limitador);
	free(limitador);
	close(file_in);
	file_in = open(".here_doc_tmp", O_RDONLY);
	if (file_in == -1)
		print_error("Error opening temp file\n");
	unlink(".here_doc_tmp");
	dup2(file_in, STDIN_FILENO);
	close(file_in);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	execute_command(argv[3], envp);
}
