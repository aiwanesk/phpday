/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:39 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:40 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	sh_exit(t_cmd *cmd)
{
	int		i;

	i = 0;
	if (cmd == NULL || cmd->tl == 1)
	{
		if (cmd == NULL)
			ft_putchar('\n');
		exit(0);
	}
	else if (cmd->tl > 2)
	{
		ft_putendl("Exit: too many arguments.");
		cmd->ret = 1;
	}
	else
	{
		while (cmd->tab[1][i])
		{
			if (!ft_isdigit(cmd->tab[1][i]) && cmd->tab[1][0] != '-')
				exit(0);
			i++;
		}
		exit(ft_atoi(cmd->tab[1]));
	}
}
