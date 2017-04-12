/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:05:18 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 12:58:36 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	*ft_memalloc(size_t size)
{
	size_t			i;
	void			*p;
	unsigned char	*dst;

	p = malloc(size * sizeof(size_t));
	if (!p)
		return (0);
	dst = (unsigned char *)p;
	i = 0;
	while (i <= size)
	{
		dst[i] = '\0';
		i++;
	}
	return (p);
}
