/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:13:33 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 22:08:03 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;
	size_t			i;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ucs1[i] != ucs2[i])
			return (ucs1[i] - ucs2[i]);
		i++;
	}
	return (0);
}

/*
** 2. Manual
*/

/*
** MEMCMP(3)                BSD Library Functions Manual               MEMCMP(3)
***
** NAME
**      memcmp -- compare byte string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      int
**      memcmp(const void *s1, const void *s2, size_t n);
***
** DESCRIPTION
**      The memcmp() function compares byte string s1 against byte string s2.
**      Both strings are assumed to be n bytes long.
***
** RETURN VALUES
**      The memcmp() function returns zero if the two strings are identical,
**      otherwise returns the difference between the first two differing bytes
**      (treated as unsigned char values, so that `\200' is greater than `\0',
**      for example).  Zero-length strings are always identical.
***
** SEE ALSO
**      bcmp(3), strcasecmp(3), strcmp(3), strcoll(3), strxfrm(3), wmemcmp(3)
***
** STANDARDS
**      The memcmp() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              June 4, 1993                             BSD
*/
