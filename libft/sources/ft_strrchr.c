/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:22:50 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 02:14:34 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	c_c;
	char	*ret_s;

	c_c = (char)c;
	i = ft_strlen(s);
	ret_s = (char*)s;
	while (i >= 0)
	{
		if (s[i] == c_c)
			return (ret_s + i);
		i--;
	}
	return (NULL);
}
