/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:27:47 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:33:08 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Simple
*/

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
** 2. Manual
*/

/*
***
** ISDIGIT(3)               BSD Library Functions Manual              ISDIGIT(3)
***
** NAME
**      isdigit, isnumber -- decimal-digit character test
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <ctype.h>
***
**      int
**      isdigit(int c);
***
**      int
**      isnumber(int c);
***
** DESCRIPTION
**      The isdigit() function tests for a decimal digit character.  Regardless
**      of locale, this includes the following characters only:
***
**      ``0''         ``1''         ``2''         ``3''         ``4''
**      ``5''         ``6''         ``7''         ``8''         ``9''
***
**      The isnumber() function behaves similarly to isdigit(), but may
**      recognize additional characters, depending on the current locale
**      setting.
***
**      The value of the argument must be representable as an unsigned char or
**      the value of EOF.
***
** RETURN VALUES
**      The isdigit() and isnumber() functions return zero if the character
**      tests false and return non-zero if the character tests true.
***
** COMPATIBILITY
**      The 4.4BSD extension of accepting arguments outside of the range of the
**      unsigned char type in locales with large character sets is considered
**      obsolete and may not be supported in future releases.  The iswdigit()
**      function should be used instead.
***
** SEE ALSO
**      ctype(3), isalnum_l(3), iswdigit(3), multibyte(3), ascii(7)
***
** STANDARDS
**      The isdigit() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** HISTORY
**      The isnumber() function appeared in 4.4BSD.
***
** BSD                               May 4, 2007                             BSD
*/
