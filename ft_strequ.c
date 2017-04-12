/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:07:21 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 19:33:34 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

/*
** 1.2 Recursive
** [NOT VERIFIED]
*/

/*
**int	ft_strequ(char const *s1, char const *s2)
**{
**	if (!s1 && !s2)
**		return (1);
**	return (*s1 == *s2 && ft_strequ(s1 + 1, s2 + 1));
**}
*/

/*
** 1.3 Composite
** [NOT VERIFIED]
*/

/*
**int	ft_strequ(cahr const *s1, char const *s2)
**{
**	return (ft_strnequ(s1, s2, ft_strlen(s1) + 1));
**}
*/
