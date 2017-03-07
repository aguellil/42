/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 06:14:31 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:47:10 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void		ft_map_data_write(t_map *map, int i, int j, int fd)
{
	if (map->data[i][j] / 10 == 1)
		ft_str_write("\033[1;33m", fd);
	if (map->data[i][j] / 10 == 2)
		ft_str_write("\033[1;34m", fd);
	if (0 <= map->data[i][j] % 10 && map->data[i][j] % 10 <= 6)
		ft_char_write('0' + map->data[i][j] % 10, fd);
	if (map->data[i][j] % 10 == 7)
		ft_char_write('|', fd);
	if (map->data[i][j] % 10 == 8)
		ft_char_write('-', fd);
	ft_str_write("\033[0;m", fd);
	return ;
}

void			ft_map_write(t_map *map, int fd)
{
	int		i;
	int		j;

	j = 0;
	ft_char_write(' ', fd);
	while (j < map->m)
	{
		ft_char_write(' ', fd);
		ft_char_write('0' + j % 10, fd);
		j++;
	}
	ft_char_write('\n', fd);
	i = 0;
	while (i < map->n)
	{
		ft_char_write('0' + i % 10, fd);
		j = 0;
		while (j < map->m)
		{
			ft_char_write(' ', fd);
			ft_map_data_write(map, i, j++, fd);
		}
		ft_str_write("\n", fd);
		i++;
	}
	return ;
}
