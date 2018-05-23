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

void			update_pwd(char *path)
{
	t_env	*ptr;
	char	*pwd;

	ptr = my_env;
	while (!ft_strstr(ptr->name, "PWD") && ptr)
		ptr = ptr->next;
	pwd = ptr->data;
	ptr->data = path;
	while (!ft_strstr(ptr->name, "OLDPWD") && ptr)
		ptr = ptr->next;
	free(ptr->data);
	ptr->data = pwd;
}

static int		cd_error(int error_id, char **command)
{
	if (error_id == 0)
	{
		error("Invalid path: ", command[1]);
		return (1);
	}
	else if (error_id != 'd')
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
	if (command[1] == NULL)
		return (find_env("HOME"));
	if (ft_strstr(command[1], "-"))
		return (find_env("OLDPWD"));
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
	update_pwd(path);
	chdir(path);
	//use getcwd to update path update after chdir
}
