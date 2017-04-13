/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 23:03:44 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 04:11:19 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_copy(char const *s, char *trim_s, int begin, int end)
{
	int		i;

	i = 0;
	while (i < (end - begin + 1))
	{
		trim_s[i] = s[begin + i];
		i++;
	}
	trim_s[i] = '\0';
	return (trim_s);
}

char			*ft_strtrim(char const *s)
{
	char	*trim_s;
	int		i;
	int		begin;
	int		end;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	begin = i;
	while (s[i] != '\0')
		i++;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || !s[i]) && i > begin)
		i--;
	end = i;
	trim_s = (char*)malloc(sizeof(*trim_s) * (end - begin + 2));
	if (trim_s == NULL)
		return (NULL);
	ft_copy(s, trim_s, begin, end);
	return (trim_s);
}
