/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 16:34:55 by aiwanesk          #+#    #+#             */
/*   Updated: 2015/06/16 16:34:56 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static char		*str_next(char *dest, const char *src, int len)
{
	char			*cpy;

	cpy = ft_strnew(ft_strlen(dest) + len);
	cpy = ft_strcpy(cpy, dest);
	cpy = ft_strncat(cpy, src, len);
	free(dest);
	return (cpy);
}

static int		get_line(char **line, char **buff, char *str, int len)
{
	char			*cpy;

	*line = str_next(*line, *buff, len);
	cpy = ft_strnew(BUFF_SIZE);
	cpy = ft_strcpy(cpy, str + 1);
	free(*buff);
	*buff = cpy;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			*str;
	static char		*buff = NULL;

	if (line == NULL)
		return (-1);
	*line = ft_strnew(0);
	if (buff)
	{
		if ((str = ft_strchr(buff, '\n')))
			return (get_line(line, &buff, str, str - buff));
		*line = str_next(*line, buff, ft_strlen(buff));
	}
	else
		buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if ((str = ft_strchr(buff, '\n')) || ret == 0)
			return (get_line(line, &buff, str, str - buff));
		*line = str_next(*line, buff, ret);
	}
	if (ret == 0)
		ft_strdel(&buff);
	return (ret);
}
