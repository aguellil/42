/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 03:17:27 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/26 23:01:14 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int			main(int argc, char *argv[])
{
	int			fd;
	t_tetri		*list;
	int			nb_tetriminos;
	int			square_s;

	nb_tetriminos = 0;
	list = NULL;
	if (argc != 2)
		ft_launch_error("not_and_too_arg", 1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_launch_error("open/close", 1);
	ft_ctrl_file(fd, &nb_tetriminos);
	if (close(fd) == -1)
		ft_launch_error("open/close", 1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_launch_error("open/close", 1);
	ft_stock_tetriminos(fd, &list);
	square_s = ft_min_square_side(nb_tetriminos);
	if (ft_resolve(list, square_s, nb_tetriminos) != NULL)
		ft_launch_error_lst(list, fd);
	ft_lstdel(&list);
	if (close(fd) == -1)
		ft_launch_error("open/close", 1);
	return (0);
}
