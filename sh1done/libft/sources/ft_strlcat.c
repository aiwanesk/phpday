/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:22:21 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:22:23 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	size_n;

	size_n = size;
	size_dst = ft_strlen(dst);
	size_src = ft_strlen(src);
	while (*dst && size_n)
	{
		dst++;
		size_n--;
	}
	if (!size_n)
		return (size + size_src);
	while (*src && size_n > 1)
	{
		*dst++ = *src++;
		size_n--;
	}
	*dst = '\0';
	return (size_dst + size_src);
}
