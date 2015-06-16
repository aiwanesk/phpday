/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <aiwanesk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/11 20:16:23 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/02/11 20:16:24 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = (t_list*)malloc(sizeof(t_list));
	if (new_elem == NULL)
		return (NULL);
	if (!content || !content_size)
	{
		new_elem->content = NULL;
		new_elem->content_size = 0;
	}
	else
	{
		if (!(new_elem->content = (void *)malloc(sizeof(content))))
			return (NULL);
		if (content_size >= 4294967295)
			return (NULL);
		if (!(ft_memcpy(new_elem->content, content, content_size + 1)))
			return (NULL);
		new_elem->content_size = content_size;
	}
	new_elem->next = NULL;
	return (new_elem);
}
