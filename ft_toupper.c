/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:31:59 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:49:49 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Inplementation
*/

/*
** 1.1 Simple
*/

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		return ('A' + c - 'a');
	return (c);
}

/*
** 2. Manual
*/

/*
***
** TOUPPER(3)               BSD Library Functions Manual              TOUPPER(3)
***
** NAME
**      toupper, toupper_l -- lower case to upper case letter conversion
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <ctype.h>
***
**      int
**      toupper(int c);
***
**      #include <ctype.h>
**      #include <xlocale.h>
***
**      int
**      toupper_l(int c, locale_t loc);
***
** DESCRIPTION
**      The toupper() function converts a lower-case letter to the corresponding
**      upper-case letter.  The argument must be representable as an unsigned
**      char or the value of EOF.
***
**      Although the toupper() function uses the current locale, the toupper_l()
**      function may be passed a locale directly. See xlocale(3) for more infor-
**      mation.
***
** RETURN VALUES
**      If the argument is a lower-case letter, the toupper() function returns
**      the corresponding upper-case letter if there is one; otherwise, the
**      argument is returned unchanged.
***
** COMPATIBILITY
**      The 4.4BSD extension of accepting arguments outside of the range of the
**      unsigned char type in locales with large character sets is considered
**      obsolete and may not be supported in future releases.  The towupper()
**      function should be used instead.
***
** SEE ALSO
**      ctype(3), isupper(3), towupper(3), xlocale(3)
***
** STANDARDS
**      The toupper() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              July 17, 2005                            BSD
*/
