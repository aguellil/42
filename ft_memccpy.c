/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:37:47 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 22:04:31 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ucdst;
	unsigned char	*ucsrc;
	unsigned char	uc;
	size_t			i;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ucdst[i] = ucsrc[i];
		if (ucsrc[i] == uc)
			return (ucdst + i + 1);
		i++;
	}
	return (0);
}

/*
** 2. Manual
*/

/*
** MEMCCPY(3)               BSD Library Functions Manual              MEMCCPY(3)
***
** NAME
**      memccpy -- copy string until character found
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      void *
**      memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
***
** DESCRIPTION
**      The memccpy() function copies bytes from string src to string dst.  If
**      the character c (as converted to an unsigned char) occurs in the string
**      src, the copy stops and a pointer to the byte after the copy of c in the
**      string dst is returned.  Otherwise, n bytes are copied, and a NULL
**      pointer is returned.
***
**      The source and destination strings should not overlap, as the behavior
**      is undefined.
***
** SEE ALSO
**      bcopy(3), memcpy(3), memmove(3), strcpy(3)
***
** HISTORY
**      The memccpy() function first appeared in 4.4BSD.
***
** BSD                              June 9, 1993                             BSD
*/
