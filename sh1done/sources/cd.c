/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:09 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:10 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		error_cd(int error, char *file, t_cmd *cmd)
{
	ft_putstr("cd: ");
	if (error == 0)
		ft_putstr("no such file or directory: ");
	else if (error == 1)
		ft_putstr("not a directory: ");
	else if (error == 2)
		ft_putstr("permission denied: ");
	else if (error == 3)
		ft_putstr("too many arguments.");
	else if (error == 4)
		ft_putstr("no variable HOME in the environnement.");
	else if (error == 5)
		ft_putstr("no variable OLDPWD in the environnement.");
	ft_putendl(file);
	cmd->ret = 1;
}

static void		change_dir(char *path, t_cmd *cmd)
{
	if (!ft_strcmp(path, "~"))
	{
		if (is_in_env(cmd->env, "HOME") != -1
				&& get_var_env("HOME", cmd->env))
			path = cmd->home;
		else
			error_cd(4, "", cmd);
	}
	else if (!ft_strcmp(path, "-"))
	{
		if (is_in_env(cmd->env, "OLDPWD") != -1
				&& get_var_env("OLDPWD", cmd->env))
			path = cmd->oldpwd;
		else
			error_cd(5, "", cmd);
	}
	cg_oldpwd(cmd);
	chdir(path);
	cg_pwd(cmd);
}

void			sh_cd(char *path, t_cmd *cmd)
{
	struct stat		sf;

	if (!ft_strcmp(path, "-") || !ft_strcmp(path, "~"))
	{
		change_dir(path, cmd);
		return ;
	}
	if (!access(path, F_OK))
	{
		stat(path, &sf);
		if ((sf.st_mode & S_IFMT) == S_IFDIR)
		{
			if (!access(path, X_OK))
			{
				change_dir(path, cmd);
				return ;
			}
			error_cd(2, path, cmd);
			return ;
		}
		error_cd(1, path, cmd);
		return ;
	}
	error_cd(0, path, cmd);
	return ;
}

void			parse_cd(t_cmd *cmd)
{
	if (cmd->tl > 2)
		error_cd(3, "", cmd);
	else if (cmd->tl == 1)
	{
		if (cmd->home)
			sh_cd(cmd->home, cmd);
		else
			error_cd(4, "", cmd);
	}
	else
		sh_cd(cmd->tab[1], cmd);
}
