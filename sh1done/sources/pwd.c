/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:50 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:50 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		pwd_error(int error, t_cmd *cmd)
{
	ft_putstr("pwd: ");
	if (error == 0)
		ft_putendl("too many arguments");
	if (error == 1)
		ft_putendl("can't find where you are.");
	cmd->ret = 1;
}

void			sh_pwd(t_cmd *cmd)
{
	char	*str;

	if (cmd->tl > 1)
		pwd_error(0, cmd);
	str = getcwd(NULL, 0);
	if (str != NULL)
		ft_putendl(str);
	else
		pwd_error(1, cmd);
}
