/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unix_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:20:15 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/15 11:20:16 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		**get_path(char **command)
{
	char	*tmp;
	char	**path;
	int		i;

	i = 0;
	tmp = find_env("PATH");
	if (tmp == NULL)
		return (NULL);
	path = ft_strsplit(tmp, ':');
	while (path[i])
	{
		path[i] = ft_str_fjoin(path[i], "/", 1);
		path[i] = ft_str_fjoin(path[i], command[0], 1);
		i++;
	}
	return (path);
}

static char		*get_exec(char **command)
{
	char	*res;
	char	**path;
	int		i;

	i = 0;
	if (ft_strchr(command[0], '/') && (access(command[0], X_OK) == 0))
		return (ft_strdup(command[0]));
	path = get_path(command);
	if (path == NULL)
		return (NULL);
	while (path[i])
	{
		if (access(path[i], X_OK) == 0)
		{
			res = ft_strdup(path[i]);
			ft_free_tab(path);
			return (res);
		}
		i++;
	}
	ft_free_tab(path);
	return (NULL);
}

int				execute(char **command)
{
	char	*path;
	pid_t	father;
	char	**env;

	path = get_exec(command);
	if (path == NULL)
		return (0);
	env = get_env();
	father = fork();
	if (father == 0)
		execve(path, command, env);
	if (father > 0)
		wait(&father);
	free(path);
	ft_free_tab(env);
	return (1);
}
