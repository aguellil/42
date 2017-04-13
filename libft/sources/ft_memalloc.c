/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 02:06:59 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/04 03:21:39 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void				*alloc;
	unsigned char		*c_alloc;

	alloc = (void*)malloc(sizeof(size_t) * size);
	if (alloc == NULL)
		return (NULL);
	c_alloc = (unsigned char*)alloc;
	ft_bzero(c_alloc, size);
	return (alloc);
}
