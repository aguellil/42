/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 23:48:33 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/12 01:21:41 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** In one string, find number of strings delimited by a character.
*/

static size_t		ft_count_strings(char const *s, char c)
{
	size_t		i;
	size_t		strings;

	i = 0;
	strings = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		strings++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (strings);
}

/*
** Creation of string
*/

static char			*ft_create_strings(char const *s, char c, size_t *i)
{
	size_t		k;
	char		*str;

	str = (char*)malloc(sizeof(*str) * ft_strlen(s));
	if (str == NULL)
		return (NULL);
	k = 0;
	while (s[*i] && s[*i] != c)
	{
		str[k] = s[*i];
		k++;
		*i += 1;
	}
	str[k] = '\0';
	while (s[*i] && s[*i] == c)
		*i += 1;
	return (str);
}

static char			**ft_free_tab(char **s_tab, size_t *j)
{
	while (*j != 0)
	{
		free(s_tab[*(j - 1)]);
		*j -= 1;
	}
	free(s_tab[*j]);
	free(*s_tab);
	*s_tab = NULL;
	return (NULL);
}

/*
** Obtain a strings table, from one string, when using a delimiter character.
*/

char				**ft_strsplit(char const *s, char c)
{
	char			**s_tab;
	size_t			len_tab;
	size_t			i;
	size_t			j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	len_tab = ft_count_strings(s, c);
	s_tab = (char**)malloc(sizeof(*s_tab) * (len_tab + 1));
	if (s_tab == NULL)
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && j < len_tab)
	{
		s_tab[j] = ft_create_strings(s, c, &i);
		if (s_tab[j] == NULL)
			return (ft_free_tab(s_tab, &j));
		j++;
	}
	s_tab[j] = 0;
	return (s_tab);
}
