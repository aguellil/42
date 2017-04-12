/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 18:47:31 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/19 00:30:49 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

/*
** 1.1.1 Without temporary memory allocation
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*ucdst;
	unsigned char	*ucsrc;

	ucdst = (unsigned char *)dst;
	ucsrc = (unsigned char *)src;
	if (ucsrc < ucdst && ucdst < ucsrc + len)
	{
		i = len - 1;
		while (i >= 0)
		{
			ucdst[i] = ucsrc[i];
			i = i - 1;
		}
	}
	else
	{
		i = 0;
		while ((size_t)i < len)
		{
			ucdst[i] = ucsrc[i];
			i = i + 1;
		}
	}
	return (dst);
}

/*
** 1.1.2 With temporary memory allocation
*/

/*
** #include <stdlib.h>
*/

/*
** 2. Manual
*/

/*
** MEMMOVE(3)               BSD Library Functions Manual              MEMMOVE(3)
***
** NAME
**      memmove -- copy byte string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      void *
**      memmove(void *dst, const void *src, size_t len);
***
** DESCRIPTION
**      The memmove() function copies len bytes from string src to string dst.
**      The two strings may overlap; the copy is always done in a
**      non-destructive manner.
***
** RETURN VALUES
**      The memmove() function returns the original value of dst.
***
** SEE ALSO
**      bcopy(3), memccpy(3), memcpy(3), strcpy(3), wmemmove(3)
***
** STANDARDS
**      The memmove() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              June 4, 1993                             BSD
*/
