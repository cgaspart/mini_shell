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

int		main(int argc, char **argv, char **environ)
{
	char	*user_input;
	int		run;

	run = argc;
	argv = NULL;
	if (setup(environ))
	{
		while (run)
		{
			prompt();
			get_input(&user_input);
			if (user_input[0])
				run = interpretor(user_input);
			free(user_input);
		}
		free_env();
	}
	else
		ft_putstr("Failure to launch.");
	return (1);
}
