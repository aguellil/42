/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 23:00:46 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/03 23:46:57 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*c_dst;
	unsigned char		*c_src;
	int					i;

	c_dst = (unsigned char*)dst;
	c_src = (unsigned char*)src;
	if (c_src < c_dst && c_dst < (c_src + len))
	{
		i = len - 1;
		while (i >= 0)
		{
			c_dst[i] = c_src[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < len)
		{
			c_dst[i] = c_src[i];
			i++;
		}
	}
	return (dst);
}
