/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:53:07 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/04 15:13:29 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	char	*ret;
	int		j;

	j = 0;
	i = ft_strlen(str) - 1;
	ret = (char *)malloc(sizeof(char) * i);
	while (i > 0)
	{
		ret[j] = str[i];
		i--;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
