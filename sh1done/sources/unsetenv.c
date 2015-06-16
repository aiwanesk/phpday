/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:33:10 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:33:11 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		unsetenv_error(int error, char *name, t_cmd *cmd)
{
	ft_putstr("unsetenv: ");
	if (error == 0)
		ft_putendl("Incorrect number of arguments.");
	else if (error == 1)
	{
		ft_putchar('\'');
		ft_putstr(name);
		ft_putendl("' not found in env.");
	}
	cmd->ret = 1;
}

void			sh_unsetenv(char *name, t_cmd *cmd)
{
	char	**n_env;
	int		i;
	int		j;

	n_env = (char **)malloc(sizeof(char *) * (ft_tablen(cmd->env)));
	i = 0;
	j = 0;
	while (cmd->env[i])
	{
		if (ft_strncmp(cmd->env[i], ft_strjoin(name, "="), ft_strlen(name) + 1))
		{
			n_env[j] = cmd->env[i];
			j++;
		}
		i++;
	}
	cmd->env = n_env;
}

void			parse_unsetenv(t_cmd *cmd)
{
	int		i;

	i = 1;
	if (cmd->tl < 2)
		unsetenv_error(0, NULL, cmd);
	else
	{
		while (cmd->tab[i])
		{
			if (is_in_env(cmd->env, cmd->tab[i]) == -1)
				unsetenv_error(1, cmd->tab[i], cmd);
			else
				sh_unsetenv(cmd->tab[i], cmd);
			i++;
		}
	}
}
