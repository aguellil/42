/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 14:34:23 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 14:57:02 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** todo
*/

#include "hotrace.h"

void	ft_bzero(void *s, size_t n)
{
	char	*swap;

	if (n)
	{
		swap = s;
		while (n--)
			*swap++ = 0;
	}
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dswap;
	const char	*sswap;

	dswap = dest;
	sswap = src;
	if (dest != src)
		while (n--)
			*dswap++ = *sswap++;
	return (dest);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			return ((void *)s);
		s = (char *)s + 1;
	}
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d_swap;
	const char	*s_swap;

	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	d_swap = (char *)dest + n;
	s_swap = (char *)src + n;
	while (n)
	{
		d_swap--;
		s_swap--;
		n--;
		*d_swap = *s_swap;
	}
	return (dest);
}
