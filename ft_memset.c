/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:33:13 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:56:26 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned int	i;
	unsigned char	uc;
	unsigned char	*ub;

	ub = (unsigned char	*)b;
	uc = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		ub[i] = uc;
		i = i + 1;
	}
	return (b);
}

/*
** 2. Manual
*/

/*
** MEMSET(3)                BSD Library Functions Manual               MEMSET(3)
***
** NAME
**      memset -- fill a byte string with a byte value
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      void *
**      memset(void *b, int c, size_t len);
***
** DESCRIPTION
**      The memset() function writes len bytes of value c (converted to an
**      unsigned char) to the string b.
***
** RETURN VALUES
**      The memset() function returns its first argument.
***
** SEE ALSO
**      bzero(3), memset_pattern(3), memset_s.3, swab(3), wmemset(3)
***
** STANDARDS
**      The memset() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              June 4, 1993                             BSD
*/
