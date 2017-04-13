/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_write_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 14:54:23 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 18:31:02 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

/*
** static void		ft_map_data_write(t_map *map, int i, int j, int fd)
** {
** 	if (map->data[i][j] / 10 == 1)
** 		ft_str_write("\033[1;33m", fd);
** 	if (map->data[i][j] / 10 == 2)
** 		ft_str_write("\033[1;34m", fd);
** 	if (0 <= map->data[i][j] % 10 && map->data[i][j] % 10 <= 6)
** 		ft_char_write('0' + map->data[i][j] % 10, fd);
** 	if (map->data[i][j] % 10 == 7)
** 		ft_char_write('|', fd);
** 	if (map->data[i][j] % 10 == 8)
** 		ft_char_write('-', fd);
** 	ft_str_write("\033[0;m", fd);
** 	return ;
** }
*/

static void		board_map_char_write_fd(t_board *board, int i, int j, int fd)
{
	char	c;

	if (board == 0)
		return ;
	c = board->map[i][j];
	if (c == -2)
		ft_putchar_fd('+', fd);
	if (c == -1)
		ft_putchar_fd(' ', fd);
	if (0 <= c && c <= 6)
		ft_putchar_fd('0' + c, fd);
}

static void		board_map_write_fd(t_board *board, int fd)
{
	int		i;
	int		j;

	j = 0;
	ft_putchar_fd(' ', fd);
	while ((size_t)j < board->xsize)
	{
		ft_putchar_fd(' ', fd);
		ft_putchar_fd('0' + j % 10, fd);
		j++;
	}
	ft_putchar_fd('\n', fd);
	i = 0;
	while ((size_t)i < board->ysize)
	{
		ft_putchar_fd('0' + i % 10, fd);
		j = 0;
		while ((size_t)j < board->xsize)
		{
			ft_putchar_fd(' ', fd);
			board_map_char_write_fd(board, i, j++, fd);
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}

void			board_write_fd(t_board *board, int fd)
{
	ft_putstr_fd("Xsize: ", fd);
	ft_putnbr_fd(board->xsize, fd);
	ft_putstr_fd("\nYsize: ", fd);
	ft_putnbr_fd(board->ysize, fd);
	ft_putstr_fd("\nMap:\n", fd);
	board_map_write_fd(board, fd);
	ft_putstr_fd("\nExtremities:\n", fd);
	while (board->extremities)
	{
		extremity_write_fd(board->extremities->content, fd);
		board->extremities = board->extremities->next;
	}
	return ;
}
