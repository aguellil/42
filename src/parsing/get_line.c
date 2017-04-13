/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 13:33:17 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 18:39:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** todo
*/

#include "parsing.h"

static void		del_read_t(t_read *read_t)
{
	free(read_t->buf);
	free(read_t);
}

static t_bool	dup_line(t_read *read_t, char **line, size_t len)
{
	*line = (char *)malloc(sizeof(char) * len + 1);
	ft_memcpy(*line, read_t->buf, len);
	ft_memmove(read_t->buf, read_t->buf + len + 1, read_t->length - len);
	ft_bzero(read_t->buf + read_t->length - len, read_t->length - len);
	read_t->length -= len + 1;
	*(*line + len) = 0;
	return (TRUE);
}

static void		increase_buf(t_read *read_t)
{
	char	*new;

	read_t->alloc_size *= RESIZE_FACTOR;
	new = (char *)malloc(sizeof(char) * read_t->alloc_size);
	ft_memcpy(new, read_t->buf, read_t->length);
	ft_bzero((void *)(new + read_t->length), \
				read_t->alloc_size - read_t->length);
	free(read_t->buf);
	read_t->buf = new;
}

static t_read	*new_read_t(void)
{
	t_read	*read_t;

	read_t = (t_read *)malloc(sizeof(t_read));
	read_t->buf = (char *)malloc(sizeof(char) * READ_SIZE);
	ft_bzero((void *)read_t->buf, READ_SIZE);
	read_t->alloc_size = READ_SIZE;
	read_t->length = 0;
	return (read_t);
}

t_bool			get_line(char **line)
{
	static t_read	*read_t = NULL;
	ssize_t			ret;
	char			*eol;

	if (!read_t)
		read_t = new_read_t();
	else if ((eol = ft_memchr(read_t->buf, '\n', read_t->length)))
		return (dup_line(read_t, line, (size_t)(eol - read_t->buf)));
	if (read_t->length + READ_SIZE >= read_t->alloc_size)
		increase_buf(read_t);
	while ((ret = read(0, read_t->buf + read_t->length, READ_SIZE)) > 0)
	{
		read_t->length += (size_t)ret;
		if ((eol = ft_memchr(\
				read_t->buf + read_t->length - ret, '\n', (size_t)ret)))
			return (dup_line(read_t, line, (size_t)(eol - read_t->buf)));
		if (read_t->length + READ_SIZE >= read_t->alloc_size)
			increase_buf(read_t);
	}
	del_read_t(read_t);
	return (FALSE);
}
