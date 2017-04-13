/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 22:33:10 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/04 00:42:26 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	unsigned char		c_c;
	unsigned char		*c_dst;
	unsigned char		*c_src;
	size_t				i;

	c_c = (unsigned char)c;
	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	i = 0;
	while (i < len)
	{
		c_dst[i] = c_src[i];
		if (c_src[i] == c_c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
