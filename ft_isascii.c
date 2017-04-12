/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:26:55 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:32:27 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Simple
*/

int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/*
** 2. Manual
*/

/*
***
** ISASCII(3)               BSD Library Functions Manual              ISASCII(3)
***
** NAME
**      isascii -- test for ASCII character
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <ctype.h>
***
**      int
**      isascii(int c);
***
** DESCRIPTION
**      The isascii() function tests for an ASCII character, which is any
**      character between 0 and octal 0177 inclusive.
***
** SEE ALSO
**      ctype(3), iswascii(3), ascii(7)
***
** BSD                             October 6, 2002                           BSD
*/
