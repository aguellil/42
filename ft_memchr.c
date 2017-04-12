/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 19:08:17 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:54:21 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		ucc;
	const unsigned char	*ucs;
	size_t				i;

	ucc = (unsigned char)c;
	ucs = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ucs[i] == ucc)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
** 2. Manual
*/

/*
** MEMCHR(3)                BSD Library Functions Manual               MEMCHR(3)
***
** NAME
**      memchr -- locate byte in byte string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      void *
**      memchr(const void *s, int c, size_t n);
***
** DESCRIPTION
**      The memchr() function locates the first occurrence of c (converted to an
**      unsigned char) in string s.
***
** RETURN VALUES
**      The memchr() function returns a pointer to the byte located, or NULL if
**      no such byte exists within n bytes.
***
** SEE ALSO
**      strchr(3), strcspn(3), strpbrk(3), strrchr(3), strsep(3), strspn(3),
**      strstr(3), strtok(3), wmemchr(3)
***
** STANDARDS
**      The memchr() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              April 9, 2008                            BSD
*/
