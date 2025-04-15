/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vimazuro <vimazuro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 11:12:11 by vimazuro          #+#    #+#             */
/*   Updated: 2025/03/04 15:24:12 by vimazuro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"
# include "libft/include/get_next_line.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

int		main(int argc, char **argv, char **envp);
int		open_input_file(char *input_file);
int		open_output_file(char *output_file);
int		open_tmp_file(char *tmp_file);
int		**create_pipes(int num_pipes);
char	*find_full_path(const char *command, char **envp);
void	check_argv(int argc, char **argv);
void	print_error(char *text);
void	free_array(char **array);
void	free_pipe_array(int **pipe_fd, int num_pipes);
void	execute_command(char *command, char **envp);
void	child_process_first(char **argv, int pipe_fd[2], char **envp);
void	child_process_last(int argc, char **argv, int pipe_fd[2], char **envp);
void	child_process_middle(char *argv, int prev_pipe[2], int next_pipe[2], \
char **envp);
void	child_process_here(char **argv, int pipe_fd[2], char **envp);
void	process_two_commands(int argc, char **argv, char **envp);
void	process_mult_commands(int argc, char **argv, char **envp);
void	process_here_commands(int argc, char **argv, char **envp);
void	process_here_mult_commands(int argc, char **argv, char **envp);
void	create_first_process(char **argv, int pipe_fd[2], char **envp);
void	create_here_first_process(char **argv, int pipe_fd[2], char **envp);
void	create_last_process(int argc, char **argv, int pipe_fd[2], char **envp);
void	create_middle_process(char *argv, int prev_pipe[2], int next_pipe[2], \
char **envp);
void	write_tmp_file(int file_in, char *limitador);

#endif