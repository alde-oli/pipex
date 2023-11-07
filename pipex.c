/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:22:17 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/07 12:22:17 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void ft_close(int fd)
{
	if (fd != -1)
		close(fd);
}

static void ft_dup2(int fd1, int fd2)
{
	dup2(fd1, fd2);
	ft_close(fd1);
}

static int ft_exec_command(char *cmd, char **envp, int *fd_in, int *fd_out)
{
	char **cmd_args;

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		return (-1);

	if (fd_in != NULL)
		ft_dup2(*fd_in, STDIN_FILENO);
	if (fd_out != NULL)
		ft_dup2(*fd_out, STDOUT_FILENO);
	execve(cmd_args[0], cmd_args, envp);
	ft_free_str_tab(cmd_args);
	return (-1);
}

static int ft_setup_output(char *file_out)
{
	if (file_out == NULL)
		return (STDOUT_FILENO);
	return (open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

static void ft_child(char *cmd, char **envp, int *fd_in, int fd_out)
{
	if (fd_out != -1)
		ft_dup2(fd_out, STDOUT_FILENO);
	if (ft_exec_command(cmd, envp, fd_in, fd_out == -1 ? NULL : &fd_out) == -1)
		exit(EXIT_FAILURE);
}

static int ft_parent(pid_t pid, int fd_out)
{
	int status;

	ft_close(fd_out);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		return (-1);
	return (0);
}

int ft_fork_and_exec(char *cmd, char **envp, int *fd_in, int fd_out)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		ft_child(cmd, envp, fd_in, fd_out);
		exit(EXIT_SUCCESS);
	}
	else
		return ft_parent(pid, fd_out);
}

int main(int argc, char **argv, char **envp)
{
	int pipe_fd[2];
	int fd_in;

	ft_check_args(argc, argv);
	fd_in = open(argv[1], O_RDONLY);
	if (fd_in == -1)
		ft_error('f');
	int i = 2;
	while (i < argc - 2)
	{
		pipe(pipe_fd);
		if (ft_fork_and_exec(argv[i], envp, &fd_in, NULL) == -1)
			ft_error('e');
		ft_close(fd_in);
		fd_in = pipe_fd[0];
		ft_close(pipe_fd[1]);
		i++;
	}
	if (ft_fork_and_exec(argv[argc - 2], envp, &fd_in, argv[argc - 1]) == -1)
		ft_error('e');
	ft_close(fd_in);
	return (EXIT_SUCCESS);
}
