/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 19:48:05 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/11 19:48:07 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	t_env	*ptr;

	ptr = g_my_env;
	while (ptr)
	{
		ft_putstr(ptr->name);
		ft_putchar('=');
		ft_putstr(ptr->data);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

void	print_pwd(void)
{
	char	*home;
	char	*pwd;
	int		i;

	home = find_env("HOME");
	pwd = find_env("PWD");
	if (pwd == NULL || home == NULL)
		return ;
	i = ft_strlen(home);
	if (!ft_strncmp(home, pwd, i))
	{
		ft_putchar('~');
		ft_putstr(&pwd[i]);
	}
	else
		ft_putstr(pwd);
}
