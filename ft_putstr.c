/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 23:42:08 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:29:37 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	ft_putstr(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	return ;
}

/*
** 1.2 Recursive
*/

/*
**void	ft_putstr(char const *s)
**{
**	if (*s)
**	{
**		write(1, s, 1);
**		ft_putstr(s + 1);
**	}
**	return ;
**}
*/

/*
** 1.3 Composite
*/

/*
**void	ft_putstr(char const *s)
**{
**	ft_putstr_fd(s, 1);
**	return ;
**}
*/
