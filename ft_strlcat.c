/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:10:01 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:41:28 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lsrc;
	unsigned int	ldst;
	unsigned int	i;

	lsrc = 0;
	while (src[lsrc])
		lsrc++;
	ldst = 0;
	while (dst[ldst])
		ldst++;
	if (size != 0 && ldst < size)
	{
		i = 0;
		while (i < size - ldst - 1 && src[i])
		{
			dst[ldst + i] = src[i];
			i++;
		}
		dst[ldst + i] = '\0';
	}
	else
		ldst = size;
	return (ldst + lsrc);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**size_t	ft_strlcat(char *dst, const char *src, size_t size)
**{
**	unsigned int	lsrc;
**	unsigned int	ldst;
***
**	ft_strncpy(dst + ldst, src, size - ldst + 1);
**	return (ldst + lsrc);
**}
*/

/*
** 2. Manual
*/

/*
** STRLCPY(3)               BSD Library Functions Manual              STRLCPY(3)
***
** NAME
**      strlcpy, strlcat -- size-bounded string copying and concatenation
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      size_t
**      strlcpy(char * restrict dst, const char * restrict src, size_t size);
***
**      size_t
**      strlcat(char * restrict dst, const char * restrict src, size_t size);
***
** DESCRIPTION
**      The strlcpy() and strlcat() functions copy and concatenate strings
**      respectively.  They are designed to be safer, more consistent, and less
**      error prone replacements for strncpy(3) and strncat(3).  Unlike those
**      functions, strlcpy() and strlcat() take the full size of the buffer (not
**      just the length) and guarantee to NUL-terminate the result (as long as
**      size is larger than 0 or, in the case of strlcat(), as long as there is
**      at least one byte free in dst).  Note that a byte for the NUL should be
**      included in size.  Also note that strlcpy() and strlcat() only operate
**      on true ``C'' strings.  This means that for strlcpy() src must be
**      NUL-terminated and for strlcat() both src and dst must be NUL-
**      terminated.
***
**      The strlcpy() function copies up to size - 1 characters from the
**      NUL-terminated string src to dst, NUL-terminating the result.
***
**      The strlcat() function appends the NUL-terminated string src to the end
**      of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi-
**      nating the result.
***
**      The source and destination strings should not overlap, as the behavior
**      is undefined.
***
** RETURN VALUES
**      The strlcpy() and strlcat() functions return the total length of the
**      string they tried to create.  For strlcpy() that means the length of
**      src.
**      For strlcat() that means the initial length of dst plus the length of
**      src.  While this may seem somewhat confusing, it was done to make
**      truncation detection simple.
***
**      Note however, that if strlcat() traverses size characters without
**      finding a NUL, the length of the string is considered to be size and the
**      destination string will not be NUL-terminated (since there was no space
**      for the NUL).  This keeps strlcat() from running off the end of a
**      string.  In practice this should not happen (as it means that either
**      size is incorrect or that dst is not a proper ``C'' string).  The check
**      exists to prevent potential security problems in incorrect code.
***
** EXAMPLES
**      The following code fragment illustrates the simple case:
***
**            char *s, *p, buf[BUFSIZ];
***
**            ...
***
**            (void)strlcpy(buf, s, sizeof(buf));
**            (void)strlcat(buf, p, sizeof(buf));
***
**      To detect truncation, perhaps while building a pathname, something like
**      the following might be used:
***
**            char *dir, *file, pname[MAXPATHLEN];
***
**            ...
***
**            if (strlcpy(pname, dir, sizeof(pname)) >= sizeof(pname))
**                    goto toolong;
**            if (strlcat(pname, file, sizeof(pname)) >= sizeof(pname))
**                    goto toolong;
***
**      Since it is known how many characters were copied the first time, things
**      can be sped up a bit by using a copy instead of an append
***
**            char *dir, *file, pname[MAXPATHLEN];
**            size_t n;
***
**            ...
***
**            n = strlcpy(pname, dir, sizeof(pname));
**            if (n >= sizeof(pname))
**                    goto toolong;
**            if (strlcpy(pname + n, file, sizeof(pname) - n) >= sizeof(pname)
**               - n)
**                    goto toolong;
***
**      However, one may question the validity of such optimizations, as they
**      defeat the whole purpose of strlcpy() and strlcat().  As a matter of
**      fact, the first version of this manual page got it wrong.
***
** SEE ALSO
**      snprintf(3), strncat(3), strncpy(3), wcslcpy(3)
***
** HISTORY
**      The strlcpy() and strlcat() functions first appeared in OpenBSD 2.4, and
**      made their appearance in FreeBSD 3.3.
***
** BSD                              June 22, 1998                            BSD
*/
