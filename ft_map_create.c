/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:02:11 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:02:13 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_map	*ft_map_create(int n, int m, char c)
{
	t_map	*map;
	int		i;
	int		j;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->n = n;
	map->m = m;
	if (!(map->data = (char **)malloc(n * sizeof(char *))))
		return (0);
	i = -1;
	while (++i < n)
	{
		map->data[i] = (char *)malloc(m * sizeof(size_t));
		if (!map->data[i])
		{
			map->n = i;
			ft_map_free(map);
			return (0);
		}
		j = -1;
		while (++j < m)
			map->data[i][j] = c;
	}
	return (map);
}
