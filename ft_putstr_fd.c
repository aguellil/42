/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 23:53:17 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:24:53 by aguellil         ###   ########.fr       */
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

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		write(fd, s + i++, 1);
	return ;
}

/*
** 1.2 Recursive
*/

/*
**void	ft_putstr_fd(char const *s, int fd)
**{
**	if (*s)
**	{
**		write(fd, s, 1);
**		ft_putstr_fd(s + 1, fd);
**	}
**	return ;
**}
*/
