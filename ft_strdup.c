/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 03:04:09 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 13:57:03 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

char	*ft_strdup(const char *s1)
{
	unsigned int	l;
	size_t			i;
	char			*dup;

	l = 0;
	while (s1[l])
		l++;
	dup = (char *)malloc((l + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (i < l)
	{
		dup[i] = s1[i];
		i = i + 1;
	}
	dup[l] = '\0';
	return (dup);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**char	*ft_strdup(const char *s1)
**{
**	unsigned int	l;
**	char			*dup;
***
**	l = ft_strlen(s1);
**	dup = (char *)malloc(size(char) * (l + 1));
**	if (dup == NULL)
**		return (NULL);
**	dup = ft_memcpy(dup, s, l);
**	dup[l] = '\0';
**	return (dup);
**}
*/

/*
** 2. Manual
*/

/*
** STRDUP(3)                BSD Library Functions Manual               STRDUP(3)
***
** NAME
**      strdup, strndup -- save a copy of a string
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <string.h>
***
**      char *
**      strdup(const char *s1);
***
**      char *
**      strndup(const char *s1, size_t n);
***
** DESCRIPTION
**      The strdup() function allocates sufficient memory for a copy of the
**      string s1, does the copy, and returns a pointer to it.  The pointer may
**      subsequently be used as an argument to the function free(3).
***
**      If insufficient memory is available, NULL is returned and errno is set
**      to ENOMEM.
***
**      The strndup() function copies at most n characters from the string s1
**      always NUL terminating the copied string.
***
** SEE ALSO
**      free(3), malloc(3)
***
** HISTORY
**      The strdup() function first appeared in 4.4BSD.  The strndup() function
**      was added in FreeBSD 7.2.
***
** BSD                            December 5, 2008                           BSD
*/
