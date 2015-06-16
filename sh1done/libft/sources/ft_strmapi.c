/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:22:49 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:22:50 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;
	char	*str;

	i = 0;
	if (!(*f) || !s)
		return (NULL);
	ptr = (char *)s;
	str = ft_strnew(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	while (ptr[i])
	{
		str[i] = f(i, ptr[i]);
		i++;
	}
	return (str);
}
