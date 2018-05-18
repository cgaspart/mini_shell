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

static int		lst_len()
{
	t_env	*ptr;
	int		i;

	i = 0;
	ptr = my_env;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return(i);
}

char	*find_env(char *name)
{
	t_env *ptr;

	ptr = my_env;
	while (!ft_strstr(ptr->name, name) && ptr)
		ptr = ptr->next;
	return (ptr->data);
}

char	**get_env()
{
	char	**res;
	char	*tmp;
	t_env	*ptr;
	int		i;

	ptr = my_env;
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
