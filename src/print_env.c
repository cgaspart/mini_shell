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

void	print_env(t_env *my_env)
{
	t_env	*ptr;

	ptr = my_env;
	while (ptr)
	{
		ft_putstr(ptr->name);
		ft_putchar('=');
		ft_putstr(ptr->data);
		ft_putchar('\n');
		ptr = ptr->next;
	}
}

void	print_user(t_env *my_env)
{
	t_env *ptr;

	ptr = my_env;
	while (!ft_strstr(ptr->name, "USER"))
		ptr = ptr->next;
	ft_putstr(ptr->data);
}

void	print_pwd(t_env *my_env)
{
	char	*home_save;
	t_env	*ptr;
	int		i;

	ptr = my_env;
	while (!ft_strstr(ptr->name, "HOME"))
		ptr = ptr->next;
	home_save = ptr->data;
	ptr = my_env;
	while (!ft_strstr(ptr->name, "PWD"))
		ptr = ptr->next;
	i = ft_strlen(home_save);
	if (!ft_strncmp(home_save, ptr->data, i))
	{
		ft_putchar('~');
		home_save = &ptr->data[i];
		ft_putstr(home_save);
	}
	else
		ft_putstr(ptr->data);
}
