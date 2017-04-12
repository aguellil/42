/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 10:33:39 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 13:59:02 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	ft_bzero(void *s, size_t len)
{
	size_t			i;
	unsigned char	*ucs;

	ucs = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ucs[i] = '\0';
		i++;
	}
	return ;
}

/*
** 1.2 Recursive
*/

/*
**void	ft_bzero(void *s, size_t len)
**{
**	unsigned char	*uc;
***
**	if (len == 0)
**		return ;
**	uc = (unsigned char *)s;
**	*uc = '\0';
**	ft_bzero(s + 1, len - 1);
**}
*/

/*
** 1.3 Composite
*/

/*
**void	ft_bzero(void *s, size_t n)
**{
**	s = ft_memset(s, '\0', n);
**	return ;
**}
*/

/*
** 2. Manual
*/

/*
** BZERO(3)                 BSD Library Functions Manual                BZERO(3)
***
** NAME
**      bzero -- write zeroes to a byte string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <strings.h>
***
**      void
**      bzero(void *s, size_t n);
***
** DESCRIPTION
**      The bzero() function writes n zeroed bytes to the string s.  If n is
**      zero, bzero() does nothing.
***
** SEE ALSO
**      memset(3), swab(3)
***
** HISTORY
**      A bzero() function appeared in 4.3BSD.  Its prototype existed previously
**      in <string.h> before it was moved to <strings.h> for IEEE Std
**      1003.1-2001 (``POSIX.1'') compliance.
***
**      bzero() was deprecated in IEEE Std 1003.1-2001 (``POSIX.1'') and removed
**      in IEEE Std 1003.1-2008 (``POSIX.1'').
***
** BSD                              June 4, 1993                             BSD
*/
