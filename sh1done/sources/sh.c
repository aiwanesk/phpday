/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:58 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void			init_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->tab = NULL;
	cmd->env = NULL;
	cmd->paths = NULL;
	cmd->home = NULL;
	cmd->oldpwd = NULL;
	cmd->bin = 0;
	cmd->tl = 0;
	cmd->ret = 0;
}

static void			env_update(t_cmd *cmd)
{
	char	*home;

	if (!cmd->env)
	{
		home = getcwd(NULL, 0);
		cmd->env = (char **)malloc(sizeof(char *) * 5);
		if (home)
		{
			cmd->env[0] = ft_union("PWD", "=", home);
			cmd->env[1] = ft_union("OLDPWD", "=", home);
		}
		else
		{
			cmd->env[0] = ft_strdup("PWD=");
			cmd->env[1] = ft_strdup("OLDPWD=");
		}
		cmd->env[2] = ft_strdup("SHLVL=0");
		cmd->env[3] = ft_strdup("PATH=/bin:/usr/bin");
		cmd->env[4] = NULL;
		free(home);
	}
	cg_shlvl(cmd);
}

static void			prompt_2(char *cur, char **env)
{
	if (is_in_env(env, "SHLVL") != -1)
	{
		ft_putstr("\033[36m[\033[31m");
		ft_putstr(get_var_env("SHLVL", env));
		ft_putstr("\033[36m] ");
	}
	ft_putstr("\033[36m");
	ft_putstr(cur);
	ft_putstr(" > \033[39m");
}

void				prompt(char **env, int i)
{
	char			*cur;
	char			*home;
	char			**tab;
	static char		**e;

	if (i == 1)
		e = env;
	cur = getcwd(NULL, 0);
	home = get_var_env("HOME", e);
	if (cur && !ft_strncmp("/Volumes/Data/", cur, 14))
		cur = ft_strsub(cur, 13, ft_strlen(cur) - 13);
	if (!cur)
		cur = ft_strdup("Where am I ?");
	else if (is_in_env(e, "HOME") != -1 && !ft_strcmp(cur, home))
		cur = ft_strdup("~");
	else if (!ft_strcmp(cur, "/"))
		cur = ft_strdup("/");
	else
	{
		tab = ft_strsplit(cur, '/');
		cur = tab[ft_tablen(tab) - 1];
	}
	prompt_2(cur, e);
	free(cur);
	free(home);
}

int					main(int ac, char **av, char **envp)
{
	int		ret;
	char	*line;
	t_cmd	cmd;

	(void)ac;
	(void)av;
	init_cmd(&cmd);
	cmd.env = NULL;
	if (*envp)
		cmd.env = envp;
	env_update(&cmd);
	gestion_signal(0);
	while (1)
	{
		prompt(cmd.env, 1);
		while (!(ret = get_next_line(0, &line)))
			if (!ret)
				sh_exit(NULL);
		if (is_empty(line))
			ft_cmd(line, &cmd);
		free(line);
	}
}
