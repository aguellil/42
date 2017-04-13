/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_and_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 07:07:39 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/23 05:51:45 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_meet_up(unsigned char bin, char *cur)
{
	int		i;

	if (bin == 6)
	{
		if (*cur != EMPTY || *(cur + 1) != EMPTY)
			return (0);
		else
			return (1);
	}
	if (bin == 2 || bin == 4)
	{
		if (*cur != EMPTY)
			return (0);
		else
			return (1);
	}
	i = 3;
	while (i >= 0)
	{
		if (bin % 2 == 1 && *(cur + i) != EMPTY)
			return (0);
		bin = bin / 2;
		i--;
	}
	return (1);
}

void	ft_fill_it(unsigned char bin, char *cur, char letter, int i)
{
	if (bin == 2 || bin == 4 || bin == 6)
	{
		*cur = letter;
		if (bin == 6)
			*(cur + 1) = letter;
		i = -1;
	}
	while (i >= 0)
	{
		if (bin % 2 == 1)
			*(cur + i) = letter;
		bin = bin / 2;
		i--;
	}
	return ;
}

void	ft_fill_sq(t_tetri *list, char *sq, char ltr, int len_line)
{
	char	(*f)(unsigned char, unsigned char);

	f = ft_focus_first_bit;
	ft_fill_it(list->w, sq, ltr, 3);
	if ((list->w >= 8 && list->x >= 8) || list->w == list->x)
		ft_fill_it(list->x, sq + len_line, ltr, 3);
	else if (list->x != 0)
		ft_fill_it(list->x, sq + len_line + f(list->w, list->x), ltr, 3);
	if ((list->w >= 8 && list->y >= 8) || list->w == list->y)
		ft_fill_it(list->y, sq + (len_line * 2), ltr, 3);
	else if (list->y != 0)
		ft_fill_it(list->y, sq + (len_line * 2) + f(list->w, list->y), ltr, 3);
	if (list->z != 0)
		ft_fill_it(list->z, sq + (len_line * 3), ltr, 3);
	return ;
}

int		ft_compare(t_tetri *list, char *cur, int len_line)
{
	char	(*f)(unsigned char, unsigned char);
	int		valid;

	f = ft_focus_first_bit;
	valid = ft_meet_up(list->w, cur);
	if (valid == 1 && ((list->w >= 8 && list->x >= 8) || list->w == list->x))
		valid = ft_meet_up(list->x, cur + len_line);
	else if (list->x != 0 && valid == 1)
		valid = ft_meet_up(list->x, cur + len_line + f(list->w, list->x));
	if (valid == 1 && ((list->w >= 8 && list->y >= 8) || list->w == list->y))
		valid = ft_meet_up(list->y, cur + (len_line * 2));
	else if (list->y != 0 && valid == 1)
		valid = ft_meet_up(list->y, cur + (len_line * 2) + f(list->w, list->y));
	if (list->z != 0 && valid == 1)
		valid = ft_meet_up(list->z, cur + (len_line * 3));
	return (valid);
}
