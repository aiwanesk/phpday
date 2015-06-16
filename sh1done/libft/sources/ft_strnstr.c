/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:23:53 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:23:54 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	if (i > (size_t)ft_strlen (s1) || i > n)
		return (NULL);
	while (*s1 && i <= n)
	{
		if (!ft_memcmp(s1, s2, i))
			return ((char *)s1);
		s1++;
		n--;
	}
	return (NULL);
}
