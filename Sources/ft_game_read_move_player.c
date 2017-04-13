/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_read_move_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 20:48:18 by mnguyen           #+#    #+#             */
/*   Updated: 2016/02/28 23:39:18 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int		ft_read_len(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\n' && i < 4)
	{
		if (s[i] < '0' || s[i] > '9')
			return (4);
		i++;
	}
	return (i);
}

int		ft_atoi_check(t_matrix *mat, int move)
{
	if (move > mat->m || move < 1 || mat->data[0][move - 1] != 0)
		return (0);
	return (1);
}

int		ft_game_read_move_player(t_matrix *mat)
{
	char	*s;
	int		j;
	int		ret;

	j = 0;
	if (!(s = malloc(sizeof(char) * 4)))
		return (-1);
	while (1)
	{
		ft_putstr("Your move: ");
		if (read(0, s, 12) == -1)
		{
			ft_putstr("Error: read\n");
			return (-1);
		}
		if (ft_read_len(s) <= 3)
			if (ft_atoi_check(mat, ft_atoi(s)))
			{
				ret = ft_atoi(s) - 1;
				free(s);
				return (ret);
			}
		ft_putstr("This move is not possible.\n");
	}
}
