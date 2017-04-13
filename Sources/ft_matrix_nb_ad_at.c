/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_nb_ad_at.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 23:19:04 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 23:19:06 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

int	ft_matrix_nb_ad_at(t_matrix *mat, int i, int j, int angle)
{
	int	k;
	int	l;
	int	sign;
	int	nb_adjacents;

	sign = 1;
	nb_adjacents = 1;
	while (sign >= -1)
	{
		k = i + sign * (angle == 45 || angle == 90 || angle == 135);
		l = j + sign * ((angle == 0 || angle == 45) - (angle == 135));
		while ((k != i || l != j) \
				&& (0 <= k && k < mat->n) \
				&& (0 <= l && l < mat->m) \
				&& (mat->data[k][l] == mat->data[i][j]))
		{
			nb_adjacents++;
			k = k + sign * (angle == 45 || angle == 90 || angle == 135);
			l = l + sign * ((angle == 0 || angle == 45) - (angle == 135));
		}
		sign = sign - 2;
	}
	return (nb_adjacents);
}
