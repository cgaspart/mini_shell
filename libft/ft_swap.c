/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strswitch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 17:00:43 by cgaspart          #+#    #+#             */
/*   Updated: 2018/03/03 17:00:44 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(char **str1, char **str2)
{
	char *buffer;

	buffer = *str1;
	*str1 = *str2;
	*str2 = buffer;
}
