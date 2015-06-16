/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cg_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:13 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:14 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void			cg_pwd(t_cmd *cmd)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		while (cmd->env[i])
		{
			if (!ft_strncmp(cmd->env[i], "PWD=", 4))
				cmd->env[i] = ft_strjoin("PWD=", getcwd(NULL, 0));
			i++;
		}
	}
}

void			cg_oldpwd(t_cmd *cmd)
{
	int		i;

	i = 0;
	while (cmd->env[i])
	{
		if (!ft_strncmp(cmd->env[i], "OLDPWD=", 7))
			cmd->env[i] =
				ft_strjoin("OLDPWD=", get_var_env("PWD", cmd->env));
		i++;
	}
}

void			cg_shlvl(t_cmd *cmd)
{
	int		i;

	i = ft_atoi(get_var_env("SHLVL", cmd->env));
	i++;
	sh_setenv("SHLVL", ft_itoa(i), 1, cmd);
}

int				is_in_env(char **env, char *name)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = (char *)malloc(ft_strlen(name) + 3);
	ft_strcat(str, name);
	ft_strcat(str, "=");
	len = ft_strlen(str);
	while (env && env[i])
	{
		if (!ft_strncmp(str, env[i], len))
			return (i);
		i++;
	}
	return (-1);
}

char			*get_var_env(char *name, char **env)
{
	char	**tab;
	char	*pwd;
	int		i;

	i = -1;
	if (!ft_strcmp(name, "PWD"))
		if ((pwd = getcwd(NULL, 0)) != NULL)
			return (pwd);
	while (env[++i])
	{
		tab = ft_strsplit(env[i], '=');
		if (ft_strcmp(tab[0], name) == 0)
			return (tab[1]);
	}
	return (NULL);
}
