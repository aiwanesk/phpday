/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:17:53 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:17:55 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_src;
	char	*ptr_dst;

	ptr_src = (char *)src;
	ptr_dst = (char *)dst;
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	ptr_dst += len;
	ptr_src += len;
	while (len)
	{
		*--ptr_dst = *--ptr_src;
		len--;
	}
	return (dst);
}
