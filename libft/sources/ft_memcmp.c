/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 00:17:45 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/04 00:40:00 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t				i;
	unsigned char		*c_b1;
	unsigned char		*c_b2;

	i = 0;
	c_b1 = (unsigned char*)b1;
	c_b2 = (unsigned char*)b2;
	while (i < len)
	{
		if (c_b1[i] != c_b2[i])
			return (c_b1[i] - c_b2[i]);
		i++;
	}
	return (0);
}
