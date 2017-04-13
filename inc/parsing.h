/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 23:01:42 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 18:15:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H

# define PARSING_H

# define RESIZE_FACTOR 8

# include "hotrace.h"

/*
** read struct - dynamic buffer
*/
typedef struct s_read	t_read;
struct					s_read
{
	char	*buf;
	size_t	alloc_size;
	size_t	length;
};

/*
** get_line.c
*/
t_bool					get_line(char **line);

#endif
