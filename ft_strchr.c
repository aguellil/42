/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 02:56:19 by aguellil          #+#    #+#             */
/*   Updated: 2015/12/13 21:13:28 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "string.h"

/*
** 1. Implementation
*/

/*
** 1.1 Via ft_memchr and ft_strlen
*/

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}

/*
** 1.2 Iterative
*/

/*
**char	*ft_strchr(const char *s, int c)
**{
**	unsigned int		i;
**	char				cc;
***
**	cc = (char)c;
**	i = 0;
**	while (s[i] != '\0')
**	{
**		if (s[i] == cc)
**			return (s + i);
**		i = i + 1;
**	}
**	return (NULL);
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
