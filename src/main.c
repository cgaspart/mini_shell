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

int main(void)
{
	char	*user_input;
	int		run;

	run = 1;
	while (run)
	{
		prompt();
		get_input(&user_input);
		run = interpretor(user_input);
		free(user_input);
	}
	return (1);
}
