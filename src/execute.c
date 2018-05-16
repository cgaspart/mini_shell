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

static char		**get_path(char **command, t_env *my_env)
{
	t_env	*ptr;
	char	**path;
	int		i;

	i = 0;
	ptr = my_env;
	while (!ft_strstr(ptr->name, "PATH"))
		ptr = ptr->next;
	path = ft_strsplit(ptr->data, ':');
	while (path[i])
	{
		path[i] = ft_str_fjoin(path[i], "/", 1);
		path[i] = ft_str_fjoin(path[i], command[0], 1);
		i++;
	}
	return (path);
}

int		execute(char **command, t_env *my_env)
{
	char	**path;
	int		i;
	pid_t	father;

	i = 0;
	path = get_path(command,my_env);
	father = fork();
	if (father == 0)
	{
		while (execve(path[i], &command[1], NULL) == -1)
			i++;
	}
	if (father > 0)
		wait(&father);
	ft_free_tab(path);
	return (1);
}
