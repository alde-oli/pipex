/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:01:07 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/03 22:09:25 by alde-oli         ###   ########.fr       */
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

# define BUFFER_SIZE 32

typedef struct s_file
{
	int		fd;
	char	*buf;
}	t_file;

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
//gnl fcts
char	*get_next_line(int fd);
char	*ft_strndup(char *src, int i);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_find_nl(char *str);


#endif