/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gthiry <gthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 14:43:21 by gthiry            #+#    #+#             */
/*   Updated: 2015/03/03 16:15:12 by gthiry           ###   ########.fr       */
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
