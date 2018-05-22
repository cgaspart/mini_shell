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

//void			update_pwd()

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
	else
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
	if (!cd_error(ft_type(command[1]), command) && !access(command[1], R_OK))
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
}
