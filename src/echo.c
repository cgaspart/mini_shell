/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:56:18 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/30 14:56:20 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			my_echo(char **command)
{
	int i;

	i = 1;
	while (command[i])
	{
		if (*command[i] == '$' && find_env(ft_strchr(command[i], '$') + 1))
			ft_putstr(find_env(ft_strchr(command[i], '$') + 1));
		else if (*command[i] != '$')
			ft_putstr(command[i]);
		ft_putchar('\n');
		i++;
	}
}
