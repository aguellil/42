/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:23:23 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 23:04:24 by aguellil         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1s2;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	s1s2 = (char *)malloc((i + j + 1) * sizeof(char));
	if (!s1s2)
		return (0);
	j = -1;
	while (s1[++j])
		s1s2[j] = s1[j];
	while (s2[j - i])
	{
		s1s2[j] = s2[j - i];
		j++;
	}
	s1s2[j] = '\0';
	return (s1s2);
}
