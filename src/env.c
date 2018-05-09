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

char			**cp_env(void)
{
	extern char		**environ;
	char			**env;
	int				i;

	i = 0;
	env = (char**)malloc(sizeof(char*) * ft_tablen(environ) + 1);
	while (environ[i])
	{
		env[i] = ft_strdup(environ[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

static char		*get_var_name(char *str);
{
	char	*name;
	int		i;

	i = 0;
	while (str[i] != ft_strchr(str, '='))
		i++;
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] != ft_strchr(str, '='))
	{
		name[i] = str[i]
		i++;
	}
	name[i] = '\0';
	return (name);
}

void			lst_env(char **env, t_env *my_env)
{
	while(env[i])
	{
		my_env->name = get_var_name(env[i]);
		my_env->data = get_var_data(emv[i]);
		i++;
	}
}

t_env			*get_env(void)
{
	t_env			*my_env;
	char			**env;
	int				i;

	i = 0;
	env = NULL;
	env = cp_env();
	my_env = (t_env*)malloc(sizeof(t_env));
	return (my_env);
}
