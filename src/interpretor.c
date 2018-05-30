/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpretor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:03:49 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/03 14:03:52 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		system_test(char **command)
{
	if (!execute(command))
		error("minishell: command not found: ", command[0]);
}

int		interpretor(char *user_input)
{
	char	**command;

	command = ft_strsplit(user_input, ' ');
	if (!ft_strcmp(command[0], "exit"))
	{
		ft_free_tab(command);
		return (0);
	}
	else if (!ft_strcmp(command[0], "env"))
		print_env();
	else if (!ft_strcmp(command[0], "cd"))
		my_cd(command);
	else if (!ft_strcmp(command[0], "setenv"))
		set_env(command[1], command[2]);
	else if (!ft_strcmp(command[0], "unsetenv"))
		unset_env(command[1]);
	else if (!ft_strcmp(command[0], "echo"))
		my_echo(command);
	else
		system_test(command);
	ft_free_tab(command);
	return (1);
}
