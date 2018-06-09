/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:59:56 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/01 12:59:59 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_var_name(char *str)
{
	char	*name;

	name = malloc((unsigned long)(ft_strchr(str, '=') - str + 1));
	ft_memcpy(name, str, (size_t)(ft_strchr(str, '=') - str + 1));
	*ft_strchr(name, '=') = 0;
	return (name);
}

static char		*get_var_data(char *str)
{
	char	*data;

	data = ft_strdup(ft_strchr(str, '=') + 1);
	return (data);
}

static void		lst_env(char **environ)
{
	t_env			*tmp;
	int				i;

	i = 0;
	tmp = (t_env*)malloc(sizeof(t_env));
	g_my_env = tmp;
	while (environ[i])
	{
		tmp->name = get_var_name(environ[i]);
		tmp->data = get_var_data(environ[i]);
		if (environ[i + 1] == NULL)
			tmp->next = NULL;
		else
		{
			tmp->next = (t_env*)malloc(sizeof(t_env));
			tmp = tmp->next;
		}
		i++;
	}
}

int				setup(char **environ)
{
	if (environ == NULL)
		return (0);
	lst_env(environ);
	if (g_my_env != NULL)
		return (1);
	else
		return (0);
}
