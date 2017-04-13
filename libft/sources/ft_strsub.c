/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 22:05:33 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 03:03:20 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub_copy;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	sub_copy = (char*)malloc(sizeof(*sub_copy) * (len + 1));
	if (sub_copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub_copy[i] = s[start + i];
		i++;
	}
	sub_copy[i] = '\0';
	return (sub_copy);
}
