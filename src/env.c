/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 16:01:04 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/08 16:01:06 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			set_env(char *name, char *data)
{
	t_env	*tmp;

	tmp = g_my_env;
	if (name == NULL || data == NULL)
	{
		ft_putstr("usage: setenv NAME DATA\n");
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_env*)malloc(sizeof(t_env));
	tmp = tmp->next;
	tmp->name = ft_strdup(name);
	tmp->data = ft_strdup(data);
	tmp->next = NULL;
}

void			unset_env(char *name)
{
	t_env	*ptr;
	t_env	*tmp;

	ptr = g_my_env;
	if (name == NULL)
	{
		ft_putstr("unsetenv: not enough arguments");
		return ;
	}
	while (ptr->next && !ft_strstr(ptr->next->name, name))
		ptr = ptr->next;
	if (ptr->next == NULL)
		return ;
	tmp = ptr->next->next;
	free(ptr->next->name);
	free(ptr->next->data);
	free(ptr->next);
	ptr->next = tmp;
}

char			*find_env(char *name)
{
	t_env *ptr;

	ptr = g_my_env;
	while (!ft_strstr(ptr->name, name) && ptr->next)
		ptr = ptr->next;
	if (ft_strcmp(name, ptr->name))
		return (NULL);
	return (ptr->data);
}

static int		lst_len(void)
{
	t_env	*ptr;
	int		i;

	i = 0;
	ptr = g_my_env;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

char			**get_env(void)
{
	char	**res;
	char	*tmp;
	t_env	*ptr;
	int		i;

	ptr = g_my_env;
	res = malloc(sizeof(char*) * lst_len() + 1);
	i = 0;
	while (ptr)
	{
		tmp = ft_strjoin(ptr->name, "=");
		res[i] = ft_str_fjoin(tmp, ptr->data, 1);
		ptr = ptr->next;
		i++;
	}
	res[i] = NULL;
	return (res);
}
