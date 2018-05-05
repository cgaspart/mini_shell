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

int		interpretor(char *user_input)
{
	char **command;

	command = str_to_wordtab(user_input);
	ft_puttab(command);
	return (1);
}
