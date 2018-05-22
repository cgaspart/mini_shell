/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 10:51:18 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/22 10:51:19 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char *error_mess, char *this_command)
{
	ft_putstr(error_mess);
	ft_putstr(this_command);
	ft_putchar('\n');
}
