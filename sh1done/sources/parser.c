/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:44 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:47 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static char		*check_tilde(char *str, t_cmd *cmd)
{
	if (!ft_strcmp(str, "~-") || !ft_strcmp(str, "-"))
	{
		if (is_in_env(cmd->env, "OLDPWD") != -1)
			str = cmd->oldpwd;
	}
	else if (!ft_strcmp(str, "~"))
	{
		if (is_in_env(cmd->env, "HOME") != -1)
			str = get_var_env("HOME", cmd->env);
	}
	else if (str[0] == '~' && str[1] == '/')
	{
		if (is_in_env(cmd->env, "HOME") != -1)
			str = ft_union(get_var_env("HOME", cmd->env)
			, &str[1], "");
	}
	else if (str[0] == '-' && str[1] == '/')
	{
		if (is_in_env(cmd->env, "OLDPWD") != -1)
			str = ft_union(get_var_env("OLDPWD", cmd->env)
			, &str[1], "");
	}
	return (str);
}

static char		**tilde(char **tab, t_cmd *cmd)
{
	int		i;

	i = -1;
	while (tab[++i])
		tab[i] = check_tilde(tab[i], cmd);
	return (tab);
}

static char		*no_space(char *line)
{
	char	*str;
	int		i;
	int		j;

	str = (char *)malloc(ft_strlen(line));
	i = 0;
	j = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]) == 0)
		{
			str[j] = line[i];
			j++;
		}
		i++;
	}
	str[j + 1] = '\0';
	return (str);
}

void			clean_cmd(t_cmd *cmd)
{
	if (cmd->paths)
		cmd->paths = NULL;
	if (cmd->tab)
		cmd->tab = NULL;
	if (cmd->home)
		cmd->home = NULL;
	if (cmd->oldpwd)
		cmd->oldpwd = NULL;
	if (cmd->cmd)
		cmd->cmd = NULL;
}

void			parse(char *line, t_cmd *cmd)
{
	int		i;

	i = 0;
	clean_cmd(cmd);
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], "PATH=", 5))
			cmd->paths = ft_strsplit(cmd->env[i] + 5, ':');
		else if (!ft_strncmp(cmd->env[i], "HOME=", 5))
			cmd->home = cmd->env[i] + 5;
		else if (!ft_strncmp(cmd->env[i], "OLDPWD=", 7))
			cmd->oldpwd = cmd->env[i] + 7;
		i++;
	}
	cmd->tab = tilde(split_space(line), cmd);
	cmd->cmd = no_space(cmd->tab[0]);
	cmd->tl = ft_tablen(cmd->tab);
	cmd->bin = 0;
}
