/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:31 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:32 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		exec_env(t_cmd *cpy, int i)
{
	if (i > 10)
	{
		if (i == 12)
			cpy->env[0] = NULL;
		i -= 10;
	}
	cpy->cmd = cpy->tab[i];
	cpy->tl -= i;
	cpy->tab = ft_newtab(cpy->tab, i);
	exec(cpy);
}

static void		fake_env(t_cmd *cpy, int i)
{
	char	**tab;

	if (i == 1)
	{
		tab = split_one(cpy->tab[i], '=');
		sh_setenv(tab[0], tab[1], 1, cpy);
	}
	else
	{
		cpy->env = (char **)malloc(sizeof(char *) * 2);
		cpy->env[0] = ft_strdup(cpy->tab[i]);
		cpy->env[1] = NULL;
	}
	if (cpy->tl == i + 1)
		sh_env(cpy->env);
	else
		exec_env(cpy, i + 1);
}

void			sh_env(char **env)
{
	int		i;

	i = 0;
	while (env && env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void			parse_env(t_cmd *cmd)
{
	int		i;
	t_cmd	cpy;
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		exit(-1);
	if (pid == 0)
	{
		cpy = *cmd;
		i = 1;
		if (cpy.tl != 1 && !ft_strcmp(cpy.tab[1], "-i"))
			i = 2;
		if (cpy.tl == 1)
			sh_env(cpy.env);
		else if (cpy.tl > i && ft_strchr(cpy.tab[i], '=')
				&& cpy.tab[i][0] != '=')
			fake_env(&cpy, i);
		else if (cpy.tl > i)
			exec_env(&cpy, i + 10);
		exit (0);
	}
	wait(NULL);
}
