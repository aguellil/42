/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 21:21:56 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 17:09:37 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < len)
		i++;
	if (i == len)
		i--;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
