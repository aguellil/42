/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 03:49:00 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/27 00:54:52 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

int			ft_ctrl_space(t_tetri *list, char *cur, int len_l, int last_u)
{
	if (list->z != 0)
	{
		last_u = ft_search_last_one_in_bin(list->z, 3);
		if ((int)ft_strnlen(cur, (len_l * 3) + last_u) < (len_l * 3) + last_u)
			return (0);
	}
	else if (list->y != 0)
	{
		last_u = ft_search_last_one_in_bin(list->y, 3);
		if ((int)ft_strnlen(cur, (len_l * 2) + last_u) < (len_l * 2) + last_u)
			return (0);
	}
	else if (list->x != 0)
	{
		last_u = ft_search_last_one_in_bin(list->x, 3);
		if ((int)ft_strnlen(cur, len_l + last_u) < len_l + last_u)
			return (0);
	}
	else
	{
		if ((int)ft_strnlen(cur, last_u) < last_u)
			return (0);
	}
	return (1);
}

char		*ft_prev(t_tetri **list, char *sq, char ***coord)
{
	if ((*list)->letter == 'A')
		return (NULL);
	*list = (*list)->prev;
	*coord -= 1;
	sq = **coord;
	return (sq);
}

void		ft_next(t_tetri **list, char *sq, char ***coord)
{
	**coord = sq;
	*coord += 1;
	*list = (*list)->next;
	return ;
}

t_tetri		*ft_analyze(t_tetri *list, char *sq, char **coord, int len_line)
{
	char	*first;

	first = sq;
	while (list)
	{
		while (*sq != EMPTY && *sq != '\0')
			sq++;
		if (ft_ctrl_space(list, sq, len_line, 4) == 0)
		{
			if ((sq = ft_prev(&list, sq, &coord)) == NULL)
				return (list);
			ft_fill_sq(list, sq, EMPTY, len_line);
			sq++;
		}
		else if (ft_compare(list, sq, len_line) == 1)
		{
			ft_fill_sq(list, sq, list->letter, len_line);
			ft_next(&list, sq, &coord);
			sq = first;
		}
		else
			sq++;
	}
	return (list);
}

t_tetri		*ft_resolve(t_tetri *list, int square_s, int nb_tetri)
{
	char		*square;
	int			len_square;
	char		**coord;

	if ((coord = (char**)malloc(sizeof(char*) * nb_tetri)) == NULL)
		return (list);
	while (list != NULL)
	{
		len_square = ft_pow(square_s, 2) + square_s;
		if ((square = (char*)malloc(sizeof(char) * (len_square + 1))) == NULL)
			return (list);
		ft_initialize_square(square, len_square, square_s);
		if ((list = ft_analyze(list, square, coord, square_s + 1)) != NULL)
		{
			free(square);
			square = NULL;
			square_s++;
		}
	}
	free(coord);
	coord = NULL;
	ft_putstr(square);
	free(square);
	square = NULL;
	return (list);
}
