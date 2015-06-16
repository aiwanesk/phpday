/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:16:59 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:17:00 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*ptr_dst;
	char	*ptr_src;

	i = 0;
	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (c == ptr_src[i])
			return (&ptr_dst[i + 1]);
		i++;
	}
	return (NULL);
}
