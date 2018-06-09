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
# include <sys/types.h>
# include <sys/wait.h>

typedef struct		s_env
{
	char			*name;
	char			*data;
	struct s_env	*next;
}					t_env;

t_env				*g_my_env;

int					setup(char **environ);
void				get_input(char **user_input);
int					interpretor(char *user_input);
char				**get_env(void);
char				*find_env(char *name);
void				print_env(void);
void				print_pwd(void);
void				free_env(void);
int					execute(char **command);
void				my_cd(char **command);
void				error(char *error_mess, char *this_command);
void				set_env(char *name, char *data);
void				unset_env(char *name);
void				my_echo(char **command);
#endif
