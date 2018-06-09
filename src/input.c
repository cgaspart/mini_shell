/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:02:03 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/02 12:02:05 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		prompt(void)
{
	ft_putchar('[');
	print_pwd();
	ft_putchar(']');
	ft_putstr(" $> ");
}

void			get_input(char **user_input)
{
	prompt();
	get_next_line(0, user_input);
}
