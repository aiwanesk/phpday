/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:14:57 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:14:59 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_cptdigit(int n)
{
	size_t			dig;

	dig = 1;
	while (n /= 10)
		dig++;
	return (dig);
}

char				*ft_itoa(int n)
{
	size_t			dig;
	size_t			ncp;
	char			*str;

	ncp = n;
	dig = ft_cptdigit(n);
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n < 0)
	{
		dig++;
		ncp = -n;
	}
	if (!(str = ft_strnew(dig)))
		return (NULL);
	str[--dig] = ncp % 10 + '0';
	while (ncp /= 10)
		str[--dig] = ncp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
