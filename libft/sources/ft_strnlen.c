/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 02:34:06 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/06 02:54:27 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	size_t		len;

	len = 0;
	while (s[len] != '\0' && len < maxlen)
		len++;
	if (s[len] == '\0')
		return (len);
	return (maxlen);
}
