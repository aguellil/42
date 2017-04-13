/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:46:44 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 02:04:11 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*s2;
	size_t		s_len;

	s_len = ft_strlen(s);
	s2 = (char*)malloc(sizeof(*s2) * (s_len + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, s);
	return (s2);
}
