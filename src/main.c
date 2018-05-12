/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:04:49 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/30 08:26:06 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(void)
{
	char	*user_input;
	t_env	*my_env;
	int		run;

	run = 1;
	my_env = get_env();
	if (setup(my_env))
	{
		while (run)
		{
			prompt(my_env);
			get_input(&user_input);
			run = interpretor(user_input, my_env);
			free(user_input);
		}
	}
	else
		ft_putstr("Failure to launch.");
	return (1);
}
