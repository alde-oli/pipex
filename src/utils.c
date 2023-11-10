/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:24:13 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 17:42:22 by alde-oli         ###   ########.fr       */
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

void	ft_start_check(int argc, char **argv, char **envp)
{
	int	i;

	if (argc < 5)
		ft_error("Usage: ./pipex file1 cmd1 ... cmdn file2");
	if (envp == NULL || *envp == NULL)
		ft_error("Environment variables are not provided.");
	if (access(argv[1], R_OK) == -1)
		ft_error("Error with file1");
	i = 2;
	while (i < argc - 2)
	{
		if (argv[i] == NULL || *argv[i] == '\0')
			ft_error("Command is empty or null.");
		i++;
	}
	if (access(argv[argc - 1], F_OK) != -1
		&& access(argv[argc - 1], W_OK) == -1)
		ft_error("Error with file2");
}
