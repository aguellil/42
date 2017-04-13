/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:54:47 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 01:42:06 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	size_t		i;

	i = 0;
	while (i < len)
	{
		if (((unsigned char*)b)[i] == (unsigned char)c)
			return ((void*)(b + i));
		i++;
	}
	return (NULL);
}
