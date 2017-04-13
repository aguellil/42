/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stocks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 09:56:33 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/27 03:10:34 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

void		ft_optimize_lines(t_tetri *tetri)
{
	unsigned char	el;

	el = (tetri->w == 0) * (1 + (tetri->x == 0) * (1 + (tetri->y == 0)));
	tetri->w = tetri->w * (el == 0) + tetri->x * (el == 1)
			+ tetri->y * (el == 2) + tetri->z * (el == 3);
	tetri->x = tetri->x * (el == 0) + tetri->y * (el == 1)
			+ tetri->z * (el == 2);
	tetri->y = tetri->y * (el == 0) + tetri->z * (el == 1);
	tetri->z = tetri->z * (el == 0);
	return ;
}

void		ft_optimize_columns(t_tetri *tetri)
{
	unsigned char	max;
	unsigned char	ec;

	max = ft_max(tetri->w, ft_max(tetri->x, ft_max(tetri->y, tetri->z)));
	ec = (max < 2) + (max < 4) + (max < 8);
	tetri->w = tetri->w * ft_pow(2, ec);
	tetri->x = tetri->x * ft_pow(2, ec);
	tetri->y = tetri->y * ft_pow(2, ec);
	tetri->z = tetri->z * ft_pow(2, ec);
	return ;
}

t_tetri		ft_stock_tetri_in_bits(char *buf, ssize_t i, t_tetri tetri)
{
	ssize_t		count_sharps;

	count_sharps = 0;
	while (count_sharps != 4)
	{
		if (buf[i] == '#')
		{
			if (i / (T_MAX + 1) == 0)
				tetri.w = tetri.w + ft_pow(2, (3 - i));
			if (i / (T_MAX + 1) == 1)
				tetri.x = tetri.x + ft_pow(2, (8 - i));
			if (i / (T_MAX + 1) == 2)
				tetri.y = tetri.y + ft_pow(2, (13 - i));
			if (i / (T_MAX + 1) == 3)
				tetri.z = tetri.z + ft_pow(2, (18 - i));
			count_sharps++;
		}
		i++;
	}
	ft_optimize_lines(&tetri);
	ft_optimize_columns(&tetri);
	return (tetri);
}

void		ft_stock_tetriminos(int fd, t_tetri **list)
{
	ssize_t		ret;
	char		buf[BUF_SIZE];
	int			i;
	t_tetri		tetri;
	char		letter;

	letter = 'A';
	ret = read(fd, buf, BUF_SIZE);
	while (ret && ret != -1)
	{
		tetri = ft_initialize_tetri(tetri, letter);
		letter++;
		i = 0;
		while (buf[i] != '#')
			i++;
		tetri = ft_stock_tetri_in_bits(buf, i, tetri);
		ft_add_link_to_end(list, tetri);
		ret = read(fd, buf, BUF_SIZE);
	}
	if (ret == -1)
		ft_launch_error("error", fd);
	if (list == NULL)
		ft_launch_error_lst(*list, fd);
}
