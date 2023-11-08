/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:01:07 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:43 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include "../mini_libft/mini_libft.h"

void	ft_close(int fd);
void	ft_dup2(int fd1, int fd2);
void	ft_error(const char *message);
void	ft_start_check(int argc, char **argv);
int		ft_exec_command(char *cmd, char **envp);

#endif