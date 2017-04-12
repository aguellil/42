/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:25:36 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:47:27 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cc;

	cc = (char)c;
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == cc)
			return ((char *)(s + i));
		i--;
	}
	return (0);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT FUNCTIONAL]
*/

/*
**char	*ft_strrchr(const char *s, int c)
**{
**	char	*p_last_occurrence;
**	char	*p_search_result;
***
**	p_last_occurrence = 0;
**	p_search_result = ft_strchr(s, c);
**	while (p_search_result)
**	{
**		p_last_occurrence = p_search_result;
**		p_search_result = ft_strchr(p_last_occurrence + 1, c);
**	}
**	return (p_last_occurrence);
**}
*/

/*
** 2. Manual
*/

/*
** STRCHR(3)                BSD Library Functions Manual               STRCHR(3)
***
** NAME
**      strchr, strrchr -- locate character in string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      char *
**      strchr(const char *s, int c);
***
**      char *
**      strrchr(const char *s, int c);
***
** DESCRIPTION
**      The strchr() function locates the first occurrence of c (converted to a
**      char) in the string pointed to by s.  The terminating null character is
**      considered to be part of the string; therefore if c is `\0', the func-
**      tions locate the terminating `\0'.
***
**      The strrchr() function is identical to strchr(), except it locates the
**      last occurrence of c.
***
** RETURN VALUES
**      The functions strchr() and strrchr() return a pointer to the located
**      character, or NULL if the character does not appear in the string.
***
** SEE ALSO
**      memchr(3), memmem(3), strcspn(3), strpbrk(3), strsep(3), strspn(3),
**      strstr(3), strtok(3), wcschr(3)
***
** STANDARDS
**      The functions strchr() and strrchr() conform to ISO/IEC 9899:1990
**      (``ISO C90'').
***
** BSD                             April 19, 1994                            BSD
*/
