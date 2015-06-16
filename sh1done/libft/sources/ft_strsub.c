/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:24:27 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/01 10:31:33 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	len_str;
	char	*str;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	if (start > len_str || len > len_str)
		return (NULL);
	if (start + len > len_str)
		return (NULL);
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	str = ft_strncpy(str, s + start, len);
	str[len] = '\0';
	return (str);
}
