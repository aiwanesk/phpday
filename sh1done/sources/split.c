/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:33:06 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:33:06 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char			**split_one(char *str, char c)
{
	int		i;
	int		j;
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * 3);
	i = 0;
	j = 0;
	while (str[i] != c)
		i++;
	tab[0] = (char *)malloc(i + 1);
	while (j != i)
	{
		tab[0][j] = str[j];
		j++;
	}
	tab[0][j] = '\0';
	tab[1] = ft_strdup(&str[j + 1]);
	tab[2] = NULL;
	return (tab);
}

static int		count_str(char const *s)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		if (!ft_isspace(s[i]) && (i == 0 || ft_isspace(s[i - 1])))
			nbr++;
		i++;
	}
	return (nbr);
}

static char		*tab_str(char const *s, int *i, char *str)
{
	int		x;
	int		len;

	x = 0;
	len = 0;
	while (ft_isspace(s[*i]) && s[*i])
		*i = *i + 1;
	while (!ft_isspace(s[len + *i]) && s[len + *i])
		len++;
	if (!(str = ft_strnew(len + 1)))
		return (0);
	while (!ft_isspace(s[*i]) && s[*i])
	{
		str[x] = s[*i];
		*i = *i + 1;
		x++;
	}
	str[x] = 0;
	return (str);
}

char			**split_space(char *s)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (s)
	{
		k = count_str(s);
		if (!(tab = (char **)malloc(sizeof(char *) * (k + 1))))
			return (0);
	}
	while (i < k)
	{
		tab[i] = tab_str(s, &j, tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
