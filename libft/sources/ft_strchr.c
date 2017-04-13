/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:44:09 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 02:00:49 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	c_c;
	char	*ret_s;

	i = 0;
	c_c = (char)c;
	ret_s = (char*)s;
	while (s[i] != '\0')
	{
		if (s[i] == c_c)
			return (ret_s + i);
		i++;
	}
	if (s[i] == c_c)
		return (ret_s + i);
	return (NULL);
}
