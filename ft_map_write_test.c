/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_write_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:04:16 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:04:38 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include "string.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 5)
		return (1);
	map = ft_map_create(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]));
	ft_map_write(map, atoi(argv[4]));
	ft_map_free(map);
}
