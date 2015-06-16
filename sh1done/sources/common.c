/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:32:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:32:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		echo_dol(t_cmd *cmd)
{
	if (cmd->tl == 2 && !strcmp(cmd->tab[1], "$?"))
	{
		ft_putnbr(cmd->ret);
		ft_putchar('\n');
		return (0);
	}
	return (1);
}

int		is_empty(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (!ft_isspace(str[i]))
			return (1);
	return (0);
}

int		ft_tablen(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

char	*ft_union(char *s1, char *s2, char *s3)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3));
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	ft_strcat(str, s3);
	return (str);
}

char	**ft_newtab(char **tab, int i)
{
	char	**n_tab;
	int		j;

	n_tab = (char **)malloc(sizeof(char *) * ft_tablen(tab) - i + 1);
	j = 0;
	while (j != i)
		j++;
	i = 0;
	while (tab[j + i])
	{
		n_tab[i] = tab[j + i];
		i++;
	}
	return (n_tab);
}
