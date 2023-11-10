/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:01:07 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 20:22:35 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "mini_libft.h"

//closes the file descriptor fd if not -1
void	ft_close(int fd);
//duplicates fd1 into fd2 and closes fd1
void	ft_dup2(int fd1, int fd2);
//prints the error message and exits the program
void	ft_error(const char *message);
//checks if the file exists, if commands are not empty and if envp is not empty
void	ft_start_check(int argc, char **argv, char **envp);
//executes the command cmd with the environment envp
int		ft_exec_command(char *cmd, char **envp);
//exectes the child routine
void	ft_child(int *pipefd, char *cmd, char **envp);
//executes the parent routine
int		ft_parent(int *pipefd, int *prev_input_fd, pid_t child_pid);

#endif