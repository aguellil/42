/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:26:33 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:46:32 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!big[i] && !little[i])
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] == little[j] && i + j < len)
			j++;
		if (!little[j])
			return ((char *)(big + i));
		i++;
	}
	return (0);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**char	*ft_strnstr(const char *big, const char *little, size_t len)
**{
**	unsigned int	i;
**	unsigned int	llittle;
***
**	llittle = ft_strlen(little);
**	if (llittle == 0)
**		return (big);
**	while (big[i] != '\0')
**	{
**		if (ft_strcmp(big + i, little, llittle) == 0)
**			return ((char *)(big + i));
**		i = i + 1;
**	}
**	return (0);
**}
*/

/*
** 2. Manual
*/

/*
** STRSTR(3)                BSD Library Functions Manual               STRSTR(3)
***
** NAME
**      strstr, strcasestr, strnstr -- locate a substring in a string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      char *
**      strstr(const char *big, const char *little);
***
**      char *
**      strcasestr(const char *big, const char *little);
***
**      char *
**      strnstr(const char *big, const char *little, size_t len);
***
**      #include <string.h>
**      #include <xlocale.h>
***
**      char *
**      strcasestr_l(const char *big, const char *little, locale_t loc);
***
** DESCRIPTION
**      The strstr() function locates the first occurrence of the
**      null-terminated string little in the null-terminated string big.
***
**      The strcasestr() function is similar to strstr(), but ignores the case
**      of both strings.
***
**      The strnstr() function locates the first occurrence of the null-termi-
**      nated string little in the string big, where not more than len
**      characters are searched.  Characters that appear after a `\0' character
**      are not searched.  Since the strnstr() function is a FreeBSD specific
**      API, it should only be used when portability is not a concern.
***
**      While the strcasestr() function uses the current locale, the
**      strcasestr_l() function may be passed a locale directly. See xlocale(3)
**      for more information.
***
** RETURN VALUES
**      If little is an empty string, big is returned; if little occurs nowhere
**      in big, NULL is returned; otherwise a pointer to the first character of
**      the first occurrence of little is returned.
***
** EXAMPLES
**      The following sets the pointer ptr to the "Bar Baz" portion of
**      largestring:
***
**            const char *largestring = "Foo Bar Baz";
**            const char *smallstring = "Bar";
**            char *ptr;
***
**            ptr = strstr(largestring, smallstring);
***
**      The following sets the pointer ptr to NULL, because only the first 4
**      characters of largestring are searched:
***
**            const char *largestring = "Foo Bar Baz";
**            const char *smallstring = "Bar";
**            char *ptr;
***
**            ptr = strnstr(largestring, smallstring, 4);
***
** SEE ALSO
**      memchr(3), memmem(3), strchr(3), strcspn(3), strpbrk(3), strrchr(3),
**      strsep(3), strspn(3), strtok(3), wcsstr(3), xlocale(3)
***
** STANDARDS
**      The strstr() function conforms to ISO/IEC 9899:1990 (``ISO C90'').
***
** BSD                            October 11, 2001                           BSD
*/
