/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 20:59:58 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/20 21:29:19 by aguellil         ###   ########.fr       */
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

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*trim_s;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	start = i;
	while (s[i])
		i++;
	while (i >= start && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || !s[i]))
		i--;
	end = i;
	trim_s = (char *)malloc((end - start + 2) * sizeof(char));
	if (!trim_s)
		return (0);
	i = 0;
	while (i < end - start + 1)
	{
		trim_s[i] = s[start + i];
		i++;
	}
	trim_s[i] = '\0';
	return (trim_s);
}
