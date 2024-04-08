/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:22:17 by alde-oli          #+#    #+#             */
/*   Updated: 2024/01/03 22:36:46 by alde-oli         ###   ########.fr       */
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

static void	ft_here_doc(const char *limiter, int *pipefd)
{
	char	*line;

	while (1)
	{
		write(1, ">", 1);
		line = get_next_line(STDIN_FILENO);
		if (!line || !ft_strncmp(line, limiter, ft_strlen(line) - 1))
			break ;
		write(pipefd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(pipefd[1]);
}

static int	ft_handle_input(char **argv, int *pipefd)
{
	int	input_fd;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (pipe(pipefd) == -1)
			ft_error("Pipe error");
		ft_here_doc(argv[2], pipefd);
		input_fd = pipefd[0];
	}
	else
	{
		input_fd = open(argv[1], O_RDONLY);
		if (input_fd == -1)
			ft_error("Error opening file1");
	}
	return (input_fd);
}

static int	ft_handle_output(int argc, char **argv)
{
	int	output_fd;

	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		output_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
		ft_error("Error opening file2");
	return (output_fd);
}


int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	input_fd;
	int	output_fd;
	int	pipefd[2];

	ft_start_check(argc, argv, envp);
	input_fd = ft_handle_input(argv, pipefd);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		i = 3;
	else
		i = 2;
	while (i < argc - 2)
	{
		ft_fork_and_exec(&input_fd, argv[i], envp);
		i++;
	}
	ft_dup2(input_fd, STDIN_FILENO);
	output_fd = ft_handle_output(argc, argv);
	ft_dup2(output_fd, STDOUT_FILENO);
	ft_exec_command(argv[argc - 2], envp);
	ft_close(input_fd);
	ft_close(output_fd);
	return (0);
}

