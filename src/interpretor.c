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

int		interpretor(char *user_input, t_env **my_env)
{
	char	**command;
	char	**env;

	command = str_to_wordtab(user_input);
	env = cp_env();
	my_env = NULL;
	if (!ft_strcmp(command[0], "exit"))
		return (0);
	if (!ft_strcmp(command[0], "env"))
		ft_puttab(env);
	ft_free_tab(command);
	return (1);
}
