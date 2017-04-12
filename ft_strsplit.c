/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 22:06:09 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/04 18:28:36 by aguellil         ###   ########.fr       */
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

static int	ft_nb_of_words(char const *s, char c)
{
	int	nb_of_words;
	int	i;

	nb_of_words = 0;
	i = 0;
	if (s[i] && s[i] != c)
		nb_of_words++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
			nb_of_words++;
		i++;
	}
	return (nb_of_words);
}

static int	ft_nb_of_chars_until(char const *s, char c)
{
	int	nb_of_chars;
	int	i;

	nb_of_chars = 0;
	i = 0;
	while (s[i] && s[i] != c)
	{
		nb_of_chars++;
		i++;
	}
	if (!s[i])
		return (-1);
	return (nb_of_chars);
}

static char	*ft_strdup_until(char const *s, char c)
{
	int		i;
	int		nb_of_chars;
	char	*dup;

	nb_of_chars = ft_nb_of_chars_until(s, c);
	dup = (char *)malloc((nb_of_chars + 1) * sizeof(char));
	if (!dup)
		return (0);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	ft_free_until(char ***p_tab_s, int k)
{
	int	i;

	if (!p_tab_s)
		return ;
	i = 0;
	while (i < k)
	{
		free((*p_tab_s)[i]);
		(*p_tab_s)[i] = 0;
		i++;
	}
	free(*p_tab_s);
	*p_tab_s = 0;
	return ;
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_of_words;
	int		i;
	int		k;
	char	**tab_s;

	nb_of_words = ft_nb_of_words(s, c);
	tab_s = (char **)malloc((nb_of_words + 1) * sizeof(char *));
	if (!tab_s)
		return (0);
	i = 0;
	k = 0;
	while (tab_s && k < nb_of_words)
	{
		if ((i == 0 || s[i - 1] == c) && s[i] && s[i] != c)
		{
			tab_s[k] = ft_strdup_until(s + i, c);
			if (!(tab_s[k]))
				ft_free_until(&tab_s, k);
			k++;
		}
		i++;
	}
	tab_s[k] = 0;
	return (tab_s);
}
