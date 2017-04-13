/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:28:34 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 05:57:35 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*join_s;
	int				i;
	int				j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	join_s = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join_s == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		join_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		join_s[i] = s2[j];
		i++;
		j++;
	}
	join_s[i] = '\0';
	return (join_s);
}
