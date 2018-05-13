/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 20:06:56 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/13 20:06:57 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env(t_env *my_env)
{
	t_env *ptr;

	ptr = my_env;
	while (my_env)
	{
		free(my_env->name);
		free(my_env->data);
		ptr = my_env->next;
		free(my_env);
		my_env = ptr;
	}
}
