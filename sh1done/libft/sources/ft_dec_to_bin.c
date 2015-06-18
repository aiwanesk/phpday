/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/18 12:02:30 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/18 12:02:31 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dec_to_bin(int n)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	count = 0;
	i = 31;
	str = ft_strnew(32);
	while (i >= 0)
	{
		j = n >> i;
		*(str + count) = (j & 1) ? '1' : '0';
		count++;
		i--;
	}
	*(str + count) = '\0';
	return (str);
}
