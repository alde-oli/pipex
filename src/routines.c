/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:28:40 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 17:47:31 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(int *pipefd, char *cmd, char **envp)
{
	ft_close(pipefd[0]);
	ft_dup2(pipefd[1], STDOUT_FILENO);
	ft_exec_command(cmd, envp);
}

int	ft_parent(int *pipefd, int *prev_input_fd, pid_t child_pid)
{
	ft_close(pipefd[1]);
	if (prev_input_fd)
		ft_close(*prev_input_fd);
	waitpid(child_pid, NULL, 0);
	return (pipefd[0]);
}
