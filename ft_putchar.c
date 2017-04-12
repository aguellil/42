/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:40:43 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:20:17 by aguellil         ###   ########.fr       */
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

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return ;
}

/*
** 1.2 Composite
*/

/*
**void	ft_putchar(char c)
**{
**	ft_putchar_fd(c, 1);
**}
*/
