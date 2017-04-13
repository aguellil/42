/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tplessis <tplessis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:45:53 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/27 00:07:35 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

/*
** Creates a matrix in memory, filled with zeroes
*/

t_matrix	*ft_matrix_create(int n, int m)
{
	t_matrix	*mat;
	int			i;
	int			j;

	if (!(mat = (t_matrix *)malloc(sizeof(t_matrix))))
		return (0);
	mat->n = n;
	mat->m = m;
	if (!(mat->data = (int **)malloc(n * sizeof(int *))))
		return (0);
	i = -1;
	while (++i < n)
	{
		mat->data[i] = (int *)malloc(m * sizeof(size_t));
		if (!mat->data[i])
		{
			mat->n = i;
			ft_matrix_free(mat);
			return (0);
		}
		j = -1;
		while (++j < m)
			mat->data[i][j] = 0;
	}
	return (mat);
}
