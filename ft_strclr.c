/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:43:29 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:33:22 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

void	ft_strclr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		s[i++] = '\0';
	return ;
}

/*
** 1.2 Recursive
*/

/*
** 1.3 Composite
*/
