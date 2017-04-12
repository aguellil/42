/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 23:44:28 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:25:17 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** 1. Implementation
*/

/*
** 1.1 Simple
*/

void	ft_putendl(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		write(1, s + i++, 1);
	write(1, "\n", 1);
	return ;
}

/*
** 1.2 Recursive
*/

/*
**void	ft_putendl(char const *s)
**{
**	if (*s)
**	{
**		write(1, s, 1);
**		ft_putendl(s + 1);
**	}
**	else
**		write(1, "\n", 1);
**	return ;
**}
*/

/*
** 1.3 Composite
*/

/*
**void	ft_putendl(char const *s)
**{
**	ft_putendl_fd(s, fd);
**}
*/
