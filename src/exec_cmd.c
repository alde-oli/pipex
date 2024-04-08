/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alde-oli <alde-oli@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:27:44 by alde-oli          #+#    #+#             */
/*   Updated: 2023/11/08 17:55:50 by alde-oli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_getenv(const char *name, char **env)
{
	int		i;
	int		name_len;

	name_len = ft_strlen(name);
	i = 0;
	while (env[i] != NULL)
	{
		if (ft_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '=')
			return (env[i] + name_len + 1);
		i++;
	}
	return (NULL);
}

static char	*join_path_with_cmd(const char *path, const char *cmd)
{
	char	*full_path;
	size_t	path_len;
	size_t	cmd_len;

	path_len = ft_strlen(path);
	cmd_len = ft_strlen(cmd);
	full_path = ft_calloc(sizeof(char) * (path_len + cmd_len + 2));
	if (!full_path)
		return (NULL);
	ft_strcpy(full_path, path);
	full_path[path_len] = '/';
	ft_strcpy(&full_path[path_len + 1], cmd);
	full_path[path_len + cmd_len + 1] = '\0';
	return (full_path);
}

static char	*check_access(char **paths, char *cmd)
{
	char	*full_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		full_path = join_path_with_cmd(paths[i], cmd);
		if (!full_path)
			continue ;
		if (access(full_path, X_OK) == 0)
			return (full_path);
		full_path = ft_free(full_path);
		i++;
	}
	return (NULL);
}

static char	*get_command_path(char *cmd, char **envp)
{
	char	*path_env;
	char	*cmd_path;
	char	**paths;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_env = ft_getenv("PATH", envp);
	if (!path_env)
		ft_error("PATH variable not found.");
	paths = ft_split(path_env, ':');
	if (!paths)
		ft_error("Split error on PATH variable.");
	cmd_path = check_access(paths, cmd);
	ft_free_str_tab(paths);
	if (!cmd_path)
		ft_error(ft_strjoin("Command not found: ", cmd));
	return (cmd_path);
}

int	ft_exec_command(char *cmd, char **envp)
{
	char	**cmd_args;
	char	*path;

	cmd_args = ft_split(cmd, ' ');
	if (cmd_args == NULL)
		ft_error("Split error");

	path = get_command_path(cmd_args[0], envp);
	if (execve(path, cmd_args, envp) == -1)
		ft_error("Execve error");

	ft_free_str_tab(cmd_args);
	path = ft_free(path);
	return (1);
}
