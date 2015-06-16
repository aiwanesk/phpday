/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:00 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:01 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <signal.h>

typedef struct		s_cmd
{
	char			*cmd;
	char			**tab;
	char			**env;
	char			**paths;
	char			*home;
	char			*oldpwd;
	int				bin;
	int				tl;
	unsigned char	ret;
}					t_cmd;

void				exec(t_cmd *cmd);
void				ft_cmd(char *line, t_cmd *cmd);
void				parse(char *line, t_cmd *cmd);
void				gestion_signal(int value);
void				prompt(char **env, int i);
void				signal_message_exec(int signum);
char				**split_space(char *s);
char				**split_one(char *s, char c);

/*
**			builtins - cd, env, exit, pwd, setenv, unsetenv
*/

void				parse_cd(t_cmd *cmd);
void				sh_cd(char *path, t_cmd *cmd);
void				parse_env(t_cmd *cmd);
void				sh_env(char **env);
void				sh_exit(t_cmd *cmd);
void				sh_pwd(t_cmd *cmd);
void				parse_setenv(t_cmd *cmd);
void				sh_setenv(char *name, char *value, int ow, t_cmd *cmd);
void				parse_unsetenv(t_cmd *cmd);
void				sh_unsetenv(char *name, t_cmd *cmd);

/*
**			cg_env - update value in env ang get info from env
*/

void				cg_pwd(t_cmd *cmd);
void				cg_oldpwd(t_cmd *cmd);
void				cg_shlvl(t_cmd *cmd);

char				*get_var_env(char *name, char **env);
int					is_in_env(char **env, char *name);

/*
**			common - common functions
*/

int					echo_dol(t_cmd *cmd);
int					is_empty(char *str);
int					ft_tablen(char **tab);
char				*ft_union(char *s1, char *s2, char *s3);
char				**ft_newtab(char **tab, int i);

#endif
