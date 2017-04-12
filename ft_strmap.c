/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 19:51:47 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 01:42:29 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*img_s;

	i = 0;
	while (s[i])
		i++;
	img_s = (char *)malloc((i + 1) * sizeof(char));
	if (!img_s)
		return (0);
	i = 0;
	while (s[i])
	{
		img_s[i] = (*f)(s[i]);
		i++;
	}
	img_s[i] = '\0';
	return (img_s);
}
