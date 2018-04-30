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
	while (42)
	{
		char *line;

		ft_putstr("$> ");
		get_next_line(0, &line);
		ft_putstr(line);
		ft_putchar('\n');
		free(line);
	}
	return (1);
}
