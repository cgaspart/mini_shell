/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_wordtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 14:13:41 by cgaspart          #+#    #+#             */
/*   Updated: 2018/05/03 14:13:43 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		word_len(char *str, int o)
{
	int i;

	i = 0;
	while (str[o] != '\0' && str[o] != '\n' && str[o] != '\t')
	{
		i++;
		o++;
	}
	return (i);
}

char	*get_next_word(char *str, int o)
{
	char	*res;
	int		i;

	i = 0;
	res = malloc(sizeof(char) * word_len(str, o) + 1);
	while (str[o + i] != '\0' && str[o + i] != '\n' && str[o + i] != '\t')
	{
		res[i] = str[o + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	**str_to_wordtab(char *str)
{
	char	**res;
	int		o;
	int		i;

	o = 0;
	i = 1;
	res = malloc(sizeof(char*) * get_nbr_word(str) + 1);
	res[0] = get_next_word(str, 0);
	while (str[o] != '\0')
	{
		if (str[o] == '\n' || str[o] == '\t')
		{
			res[i] = get_next_word(str, o + 1);
			i++;
		}
		o++;
	}
	res[i] = NULL;
	return (res);
}
