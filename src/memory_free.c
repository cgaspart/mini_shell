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

void	free_env(void)
{
	t_env *ptr;

	ptr = g_my_env;
	while (g_my_env)
	{
		free(g_my_env->name);
		free(g_my_env->data);
		ptr = g_my_env->next;
		free(g_my_env);
		g_my_env = ptr;
	}
}
