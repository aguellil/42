/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/01 17:56:30 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/03 23:43:20 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int		cut_line(char **str, char **rest, int idx_nl)
{
	char		*buff;
	char		*s;

	s = *str;
	if (!(buff = malloc((idx_nl + 1) * sizeof(char))))
		return (-1);
	ft_strncpy(buff, (const char*)s, idx_nl + 1);
	buff[idx_nl] = '\0';
	if (!(*rest = malloc((ft_strlen(s + idx_nl + 1) + 1) * sizeof(char))))
		return (-1);
	ft_strcpy(*rest, s + idx_nl + 1);
	*str = buff;
	return (1);
}

static int		is_eoline(char **str, char **rest)
{
	char		*s;
	char		*r;
	int			i;

	s = *str;
	r = *rest;
	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
	{
		*rest = NULL;
		return (0);
	}
	else
		return (cut_line(str, rest, i));
}

static int		concat_str(char **str, char *buff)
{
	char		*s;
	char		*b;

	s = *str;
	if (!(b = ft_strnew(ft_strlen(s) + ft_strlen(buff) + 1)))
		return (0);
	ft_strcat(b, s);
	ft_strcat(b, buff);
	free(s);
	*str = b;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	static char	*rest;
	char		*str;
	int			r;

	buff[BUFF_SIZE] = '\0';
	str = NULL;
	if (rest != NULL)
	{
		str = rest;
		rest = NULL;
	}
	r = 1;
	while (!is_eoline(&str, &rest) && ((r = read(fd, buff, BUFF_SIZE)) > 0))
	{
		if (str)
		{
			if (!(concat_str(&str, buff)))
				return (-1);
		}
		else
			str = ft_strdup(buff);
	}
	*line = str;
	return ((r > 0) ? 1 : r);
}
