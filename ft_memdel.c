/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:04:17 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 00:55:34 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Simple
*/

void	ft_memdel(void **ap)
{
	if (ap)
	{
		free(*ap);
		*ap = 0;
	}
	return ;
}
