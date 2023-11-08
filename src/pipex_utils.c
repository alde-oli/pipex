/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:24:13 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 13:58:03 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_close(int fd)
{
	if (fd != -1)
		close(fd);
}

void	ft_dup2(int fd1, int fd2)
{
	dup2(fd1, fd2);
	ft_close(fd1);
}

void	ft_error(const char *message)
{
	perror(message);
	exit(EXIT_FAILURE);
}

void	ft_start_check(int argc, char **argv)
{
	if (argc < 5)
		ft_error("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
}
