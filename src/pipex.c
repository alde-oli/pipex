/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:22:17 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/10 10:13:46 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_fork_and_exec(int *prev_input_fd, char *cmd, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error");
	if (pid == 0)
	{
		if (prev_input_fd)
			ft_dup2(*prev_input_fd, STDIN_FILENO);
		ft_child(pipefd, cmd, envp);
	}
	else
		*prev_input_fd = ft_parent(pipefd, prev_input_fd, pid);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	input_fd;
	int	output_fd;

	ft_start_check(argc, argv, envp);
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
		ft_error("Error with file1");
	i = 2;
	while (i < argc - 2)
	{
		ft_fork_and_exec(&input_fd, argv[i], envp);
		i++;
	}
	ft_dup2(input_fd, STDIN_FILENO);
	output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_error("Error with file2");
	ft_dup2(output_fd, STDOUT_FILENO);
	ft_exec_command(argv[argc - 2], envp);
	ft_close(input_fd);
	ft_close(output_fd);
	return (0);
}
