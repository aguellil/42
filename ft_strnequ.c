/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:14:31 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 19:30:34 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

/*
** 1.2 Recursive
** [NOT VERIFIED]
*/

/*
**int	ft_strnequ(char const *s1, char const *s2, size_t n)
**{
**	if (!s1 && !s2 || n == 0)
**		return (1);
**	return (*s1 == *s2 && ft_strnequ(s1 + 1, s2 + 1, n - 1))
**}
*/
