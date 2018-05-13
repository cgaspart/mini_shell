/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaspart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:09:19 by cgaspart          #+#    #+#             */
/*   Updated: 2018/04/30 08:28:26 by cgaspart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <unistd.h>
# include <termios.h>

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

int					setup(t_env *my_env);
void				prompt(t_env *my_env);
void				get_input(char **user_input);
int					interpretor(char *user_input, t_env *my_env);
t_env				*get_env(void);
void				print_env(t_env *my_env);
void				print_user(t_env *my_env);
void				print_pwd(t_env *my_env);
void				free_env(t_env *my_env);
#endif
