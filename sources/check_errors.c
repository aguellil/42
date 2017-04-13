/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:26:34 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/25 18:38:36 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_launch_error(char *reason, int fd)
{
	if (ft_strcmp(reason, "not_and_too_arg") == 0)
	{
		ft_putendl_fd("usage: ./fillit file", fd);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(reason, "open/close") == 0)
	{
		ft_putendl_fd("error", fd);
		exit(EXIT_FAILURE);
	}
	if (ft_strcmp(reason, "error") == 0)
	{
		close(fd);
		ft_putendl_fd("error", 1);
		exit(EXIT_FAILURE);
	}
}

void	ft_launch_error_lst(t_tetri *first, int fd)
{
	if (first != NULL)
		ft_lstdel(&first);
	close(fd);
	ft_putendl_fd("error", 1);
	exit(EXIT_FAILURE);
	return ;
}

int		ft_sharps_links(char *buf, ssize_t i)
{
	int		sharps_links;

	sharps_links = 0;
	if (i != 0 && buf[i - 1] == '#')
		sharps_links++;
	if (buf[i + 1] == '#')
		sharps_links++;
	if (i / (T_MAX + 1) != 0 && buf[i - (T_MAX + 1)] == '#')
		sharps_links++;
	if (i / (T_MAX + 1) != 3 && buf[i + (T_MAX + 1)] == '#')
		sharps_links++;
	return (sharps_links);
}

void	ft_ctrl_tetri(int fd, char *buf, ssize_t ret, int *count_tetri)
{
	ssize_t		i;
	int			sharps;
	int			sharps_lks;

	i = 0;
	sharps = 0;
	sharps_lks = 0;
	while (i < (ret - 1) && sharps <= T_MAX)
	{
		if (buf[i] != EMPTY && buf[i] != '#' && buf[i] != '\n')
			ft_launch_error("error", fd);
		if ((buf[i] != '\n' && ((i + 1) % (T_MAX + 1) == 0))
			|| (buf[i] == '\n' && ((i + 1) % (T_MAX + 1) != 0)))
			ft_launch_error("error", fd);
		if (buf[i] == '#')
		{
			sharps++;
			sharps_lks = sharps_lks + ft_sharps_links(buf, i);
		}
		i++;
	}
	*count_tetri = *count_tetri + 1;
	if (buf[i] != '\n' || sharps > T_MAX || *count_tetri > 26
		|| (sharps_lks != 6 && sharps_lks != 8))
		ft_launch_error("error", fd);
}

void	ft_ctrl_file(int fd, int *count_tetri)
{
	ssize_t		ret;
	char		buf[BUF_SIZE];

	ret = read(fd, buf, BUF_SIZE);
	while (ret != -1 && ret != 0 && ret > (BUF_SIZE - 1))
	{
		ft_ctrl_tetri(fd, buf, ret, count_tetri);
		ret = read(fd, buf, BUF_SIZE);
	}
	if (ret == 0 || ret == -1 || ret < (BUF_SIZE - 1))
		ft_launch_error("error", fd);
	if (ret == (BUF_SIZE - 1))
		ft_ctrl_tetri(fd, buf, ret, count_tetri);
	return ;
}
