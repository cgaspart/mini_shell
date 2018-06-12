/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:25:45 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/22 10:25:46 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			update_pwd(void)
{
	char	cwd[256];
	t_env	*ptr;
	char	*temp;

	ptr = g_my_env;
	while (!ft_strstr(ptr->name, "PWD") && ptr->next)
		ptr = ptr->next;
	temp = ft_strdup(ptr->data);
	free(ptr->data);
	getcwd(cwd, sizeof(cwd));
	ptr->data = ft_strdup(cwd);
	while (!ft_strstr(ptr->name, "OLDPWD") && ptr->next)
		ptr = ptr->next;
	free(ptr->data);
	ptr->data = temp;
}

static int		cd_error(int error_id, char **command)
{
	if (error_id == 0)
	{
		error("Invalid path: ", command[1]);
		return (1);
	}
	else if (error_id != 'd' && error_id != 'l')
	{
		error("Is not a directory: ", command[1]);
		return (1);
	}
	else if (access(command[1], R_OK) != 0)
	{
		error("You don't have right: ", command[1]);
		return (1);
	}
	return (0);
}

static char		*cd_parser(char **command)
{
	char	*tmp;

	if (command[1] == NULL || (ft_strstr(command[1], "~") && !command[1][1]))
		return (find_env("HOME"));
	if (ft_strstr(command[1], "-") && !command[1][1])
		return (find_env("OLDPWD"));
	if (ft_strstr(command[1], "~") && command[1][1])
	{
		tmp = command[1];
		free(command[1]);
		command[1] = ft_strjoin(find_env("HOME"), ft_strchr(tmp, '~') + 1);
	}
	if (!cd_error(ft_type(command[1]), command))
		return (command[1]);
	return (NULL);
}

void			my_cd(char **command)
{
	char *path;

	path = cd_parser(command);
	if (path == NULL)
		return ;
	chdir(path);
	update_pwd();
}
