/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:29:54 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 13:59:22 by aguellil         ###   ########.fr       */
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

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	s = (char *)malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	i = 0;
	while (i <= size)
		s[i++] = '\0';
	return (s);
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
*/
