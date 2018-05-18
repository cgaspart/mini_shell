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

static void		system_test(char **command, t_env *my_env)
{
	if (!execute(command, my_env))
	{
		ft_putstr("minishell: command not found:");
		ft_putstr(command[0]);
	}
}

int		interpretor(char *user_input, t_env *my_env)
{
	char	**command;

	command = str_to_wordtab(user_input);
	if (!ft_strcmp(command[0], "exit"))
		return (0);
	else if (!ft_strcmp(command[0], "env"))
		print_env();
	else
		system_test(command, my_env);
	ft_free_tab(command);
	return (1);
}
