/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 21:06:58 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/03 21:54:35 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char		*c_b;
	unsigned char		c_c;
	size_t				i;

	c_b = (unsigned char*)b;
	c_c = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		c_b[i] = c_c;
		i++;
	}
	return (b);
}
