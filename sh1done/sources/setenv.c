/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:54 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:55 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		setenv_error(int error, char *str, t_cmd *cmd)
{
	if (error == 0)
		ft_putendl("Usage: setenv <name> <value> <overwrite>");
	else
	{
		ft_putstr("setenv: ");
		if (error == 1)
			ft_putendl("'=' found in the name.");
		else if (error == 2)
		{
			ft_putchar('\'');
			ft_putstr(str);
			ft_putendl("' already in env and overwrite equal 0.");
			setenv_error(0, NULL, cmd);
		}
	}
	cmd->ret = 1;
}

void			sh_setenv(char *name, char *value, int ow, t_cmd *cmd)
{
	char	*n_line;
	char	**n_env;
	int		i;

	n_line = ft_union(name, "=", value);
	if ((i = is_in_env(cmd->env, name)) != -1)
	{
		if (ow != 0)
			cmd->env[i] = n_line;
		else
			setenv_error(2, name, cmd);
	}
	else
	{
		i = 0;
		n_env = malloc(sizeof(char *) * (ft_tablen(cmd->env) + 2));
		while (cmd->env && cmd->env[i])
		{
			n_env[i] = cmd->env[i];
			i++;
		}
		n_env[i] = n_line;
		n_env[i + 1] = NULL;
		cmd->env = n_env;
	}
}

void			parse_setenv(t_cmd *cmd)
{
	if (cmd->tl == 1)
		parse_env(cmd);
	else if ((ft_strchr(cmd->tab[1], '=')) != NULL)
		setenv_error(1, NULL, cmd);
	else if (cmd->tl == 3)
		sh_setenv(cmd->tab[1], cmd->tab[2], 0, cmd);
	else if (cmd->tl != 4)
		setenv_error(0, NULL, cmd);
	else
		sh_setenv(cmd->tab[1], cmd->tab[2],
			ft_atoi(cmd->tab[3]), cmd);
}
