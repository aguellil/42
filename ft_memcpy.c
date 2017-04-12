/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:19:10 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:54:51 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int				i;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	i = 0;
	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	while ((size_t)i < n)
	{
		ucdst[i] = ucsrc[i];
		i = i + 1;
	}
	return (dst);
}

/*
** 2. Manual
*/

/*
** MEMCPY(3)                BSD Library Functions Manual               MEMCPY(3)
***
** NAME
**      memcpy -- copy memory area
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      void *
**      memcpy(void *restrict dst, const void *restrict src, size_t n);
***
** DESCRIPTION
**      The memcpy() function copies n bytes from memory area src to memory area
**      dst.  If dst and src overlap, behavior is undefined.  Applications in
**      which dst and src might overlap should use memmove(3) instead.
***
** RETURN VALUES
**      The memcpy() function returns the original value of dst.
***
** SEE ALSO
**      bcopy(3), memccpy(3), memmove(3), strcpy(3), wmemcpy(3)
***
** STANDARDS
**      The memcpy() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              June 4, 1993                             BSD
*/
