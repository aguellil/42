/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:02:23 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:02:56 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	ft_map_free(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->n)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	free(map);
	map = 0;
	return ;
}
