/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 02:57:11 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:34:19 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**static int	ft_min(int i, int j)
**{
**	return ((i <= j) * i + (i > j) * j);
**}
*/

/*
**int			ft_strcmp(const char *s1, const char *s2)
**{
**	return (ft_strncmp(s1, s2, ft_min(ft_strlen(s1), ft_strlen(s2)) + 1));
**}
*/

/*
** 2. Manual
*/

/*
** STRCMP(3)                BSD Library Functions Manual               STRCMP(3)
***
** NAME
**      strcmp, strncmp -- compare strings
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      int
**      strcmp(const char *s1, const char *s2);
***
**      int
**      strncmp(const char *s1, const char *s2, size_t n);
***
** DESCRIPTION
**      The strcmp() and strncmp() functions lexicographically compare the null-
**      terminated strings s1 and s2.
***
**      The strncmp() function compares not more than n characters.  Because
**      strncmp() is designed for comparing strings rather than binary data,
**      characters that appear after a `\0' character are not compared.
***
** RETURN VALUES
**      The strcmp() and strncmp() functions return an integer greater than,
**      equal to, or less than 0, according as the string s1 is greater than,
**      equal to, or less than the string s2.  The comparison is done using
**      unsigned characters, so that `\200' is greater than `\0'.
***
** SEE ALSO
**      bcmp(3), memcmp(3), strcasecmp(3), strcoll(3), strxfrm(3), wcscmp(3)
***
** STANDARDS
**      The strcmp() and strncmp() functions conform to ISO/IEC 9899:1990
**      (``ISO C90'').
***
** BSD                            October 11, 2001                           BSD
*/
