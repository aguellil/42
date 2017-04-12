/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 22:22:26 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:39:26 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Simple
*/

int	ft_isalnum(int c)
{
	if ('a' <= c && c <= 'z')
		return (1);
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
** 1.2 Composite
*/

/*
**int	ft_isalnum(int c)
**{
**	return (ft_isalpha(c) || ft_isdigit(c));
**}
*/

/*
** 2. Manual
*/

/*
***
** ISALNUM(3)               BSD Library Functions Manual              ISALNUM(3)
***
** NAME
**      isalnum -- alphanumeric character test
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <ctype.h>
***
**      int
**      isalnum(int c);
***
** DESCRIPTION
**      The isalnum() function tests for any character for which isalpha(3) or
**      isdigit(3) is true.  The value of the argument must be representable as
**      an unsigned char or the value of EOF.
***
**      In the ASCII character set, this includes the following characters (pre-
**      ceded by their numeric values, in octal):
***
**      060 ``0''     061 ``1''     062 ``2''     063 ``3''     064 ``4''
**      065 ``5''     066 ``6''     067 ``7''     070 ``8''     071 ``9''
**      101 ``A''     102 ``B''     103 ``C''     104 ``D''     105 ``E''
**      106 ``F''     107 ``G''     110 ``H''     111 ``I''     112 ``J''
**      113 ``K''     114 ``L''     115 ``M''     116 ``N''     117 ``O''
**      120 ``P''     121 ``Q''     122 ``R''     123 ``S''     124 ``T''
**      125 ``U''     126 ``V''     127 ``W''     130 ``X''     131 ``Y''
**      132 ``Z''     141 ``a''     142 ``b''     143 ``c''     144 ``d''
**      145 ``e''     146 ``f''     147 ``g''     150 ``h''     151 ``i''
**      152 ``j''     153 ``k''     154 ``l''     155 ``m''     156 ``n''
**      157 ``o''     160 ``p''     161 ``q''     162 ``r''     163 ``s''
**      164 ``t''     165 ``u''     166 ``v''     167 ``w''     170 ``x''
**      171 ``y''     172 ``z''
***
** RETURN VALUES
**      The isalnum() function returns zero if the character tests false and
**      returns non-zero if the character tests true.
***
** COMPATIBILITY
**      The 4.4BSD extension of accepting arguments outside of the range of the
**      unsigned char type in locales with large character sets is considered
**      obsolete and may not be supported in future releases.  The iswalnum()
**      function should be used instead.
***
** SEE ALSO
**      ctype(3), isalnum_l(3), isalpha(3), isdigit(3), iswalnum(3), ascii(7)
***
** STANDARDS
**      The isalnum() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                              July 17, 2005                            BSD
*/
