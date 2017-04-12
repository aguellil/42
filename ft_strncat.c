/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:13:14 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:43:43 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (s1[i])
		i = i + 1;
	j = 0;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		i = i + 1;
		j = j + 1;
	}
	s1[i] = '\0';
	return (s1);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**char	*ft_strncat(char *s1, const char *s2, size_t n)
**{
**	ft_strncpy(s1 + ft_strlen(s1), s2, n + 1);
**	return (s1);
**}
*/

/*
** 2. Manual
*/

/*
** STRCAT(3)                BSD Library Functions Manual               STRCAT(3)
***
** NAME
**      strcat, strncat -- concatenate strings
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      char *
**      strcat(char *restrict s1, const char *restrict s2);
***
**      char *
**      strncat(char *restrict s1, const char *restrict s2, size_t n);
***
** DESCRIPTION
**      The strcat() and strncat() functions append a copy of the
**      null-terminated string s2 to the end of the null-terminated string s1,
**      then add a terminating `\0'.  The string s1 must have sufficient space
**      to hold the result.
***
**      The strncat() function appends not more than n characters from s2, and
**      then adds a terminating `\0'.
***
**      The source and destination strings should not overlap, as the behavior
**      is undefined.
***
** RETURN VALUES
**      The strcat() and strncat() functions return the pointer s1.
***
** SECURITY CONSIDERATIONS
**      The strcat() function is easily misused in a manner which enables mali-
**      cious users to arbitrarily change a running program's functionality
**      through a buffer overflow attack.  (See the FSA.)
***
**      Avoid using strcat().  Instead, use strncat() or strlcat() and ensure
**      that no more characters are copied to the destination buffer than it can
**      hold.
***
**      Note that strncat() can also be problematic.  It may be a security con-
**      cern for a string to be truncated at all.  Since the truncated string
**      will not be as long as the original, it may refer to a completely
**      different resource and usage of the truncated resource could result in
**      very incorrect behavior.  Example:
***
**      void
**      foo(const char *arbitrary_string)
**      {
**              char onstack[8] = "";
***
**      #if defined(BAD)
**              /\*
**               * This first strcat is bad behavior.  Do not use strcat!
**               *\/
**              (void)strcat(onstack, arbitrary_string);        /\* BAD! *\/
**      #elif defined(BETTER)
**              /\*
**               * The following two lines demonstrate better use of
**               * strncat().
**               *\/
**              (void)strncat(onstack, arbitrary_string,
**                  sizeof(onstack) - strlen(onstack) - 1);
**      #elif defined(BEST)
**              /\*
**               * These lines are even more robust due to testing for
**               * truncation.
**               *\/
**              if (strlen(arbitrary_string) + 1 >
**                  sizeof(onstack) - strlen(onstack))
**                      err(1, "onstack would be truncated");
**              (void)strncat(onstack, arbitrary_string,
**                  sizeof(onstack) - strlen(onstack) - 1);
**      #endif
**      }
***
** SEE ALSO
**      bcopy(3), memccpy(3), memcpy(3), memmove(3), strcpy(3), strlcat(3),
**      strlcpy(3), wcscat(3)
***
** STANDARDS
**      The strcat() and strncat() functions conform to ISO/IEC 9899:1990
**      (``ISO C90'').
***
** BSD                            December 1, 2009                           BSD
*/
