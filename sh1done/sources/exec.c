/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:35 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:35 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		sh_error(int error, t_cmd *cmd, int ret)
{
	ft_putstr("ft_minishell1: ");
	if (error == 0)
	{
		ft_putstr("Command not found: ");
		ft_putendl(cmd->cmd);
	}
	else
	{
		if (error == 1)
			ft_putendl("Fork has failed.");
		else if (error == 2)
			ft_putendl("Exec error.");
		exit(ret);
	}
	cmd->ret = 127;
}

static int		sh_cmd(t_cmd *cmd)
{
	int		ret;

	ret = 2;
	if (!ft_strcmp(cmd->cmd, "echo"))
		ret = echo_dol(cmd);
	cmd->ret = 0;
	if (ret && !(ret = ft_strcmp(cmd->cmd, "setenv")))
		parse_setenv(cmd);
	else if (ret && !(ret = ft_strcmp(cmd->cmd, "unsetenv")))
		parse_unsetenv(cmd);
	else if (ret && !(ret = ft_strcmp(cmd->cmd, "env")))
		parse_env(cmd);
	else if (ret && !(ret = ft_strcmp(cmd->cmd, "pwd")))
		sh_pwd(cmd);
	else if (ret && !(ret = ft_strcmp(cmd->cmd, "cd")))
		parse_cd(cmd);
	return (ret);
}

static int		check_bin(t_cmd *cmd)
{
	int		i;
	int		stat;
	char	*path;

	i = 0;
	stat = 0;
	while (cmd->paths && cmd->paths[i] && !stat)
	{
		path = ft_union(cmd->paths[i], "/", cmd->cmd);
		if (!access(path, X_OK))
		{
			cmd->cmd = path;
			stat = 1;
		}
		i++;
	}
	return (stat);
}

void			ft_cmd(char *line, t_cmd *cmd)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ';');
	while (tab[i])
	{
		if (is_empty(tab[i]))
		{
			parse(tab[i], cmd);
			if (!ft_strcmp(cmd->cmd, "exit"))
				sh_exit(cmd);
			else
				exec(cmd);
		}
		i++;
	}
}

void			exec(t_cmd *cmd)
{
	pid_t	pid;
	int		stat;

	stat = 0;
	if (ft_strchr(cmd->tab[0], '/'))
		cmd->bin = 1;
	if (!sh_cmd(cmd))
		return ;
	else if (cmd->bin == 1 || check_bin(cmd))
	{
		gestion_signal(1);
		if ((pid = fork()) < 0)
			sh_error(1, cmd, -1);
		else if (pid == 0)
			if ((stat = execve(cmd->cmd, cmd->tab, cmd->env)) == -1)
				sh_error(2, cmd, stat);
		wait(&stat);
		if (WIFEXITED(stat))
			cmd->ret = WEXITSTATUS(stat);
		else if (WIFSIGNALED(stat))
			signal_message_exec(WTERMSIG(stat));
		gestion_signal(0);
	}
	else
		sh_error(0, cmd, 0);
}
