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
	extern char 	**environ;


	char	*user_input;
	t_env	*my_env;
	int		run;

	run = 1;
	/*if (setup(&my_env))
	{*/
		while (run)
		{
			prompt();
			get_input(&user_input);
			run = interpretor(user_input, &my_env);
			free(user_input);
		}
	/*}
	else
		ft_putstr("Failure to launch.");*/
	return (1);
}
