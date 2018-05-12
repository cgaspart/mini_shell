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

static char		*get_var_name(char *str)
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] != *ft_strchr(str, '='))
		i++;
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != *ft_strchr(str, '='))
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

static char		*get_var_data(char *str)
{
	char	*data;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != *ft_strchr(str, '='))
		i++;
	while (str[i + j] != '\0')
		j++;
	data = malloc(sizeof(char) * j + 1);
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		data[j] = str[i + j];
		j++;
	}
	data[j] = '\0';
	return (data);
}

t_env			*lst_env(char **env)
{
	t_env	*tmp;
	t_env	*my_env;
	int		i;

	i = 0;
	tmp = (t_env*)malloc(sizeof(t_env));
	my_env = tmp;
	while (env[i])
	{
		tmp->name = get_var_name(env[i]);
		tmp->data = get_var_data(env[i]);
		if (env[i + 1] == NULL)
			tmp->next = NULL;
		else
		{
			tmp->next = (t_env*)malloc(sizeof(t_env));
			tmp = tmp->next;
		}
		i++;
	}
	return (my_env);
}

t_env			*get_env(void)
{
	extern char		**environ;

	return (lst_env(environ));
}
