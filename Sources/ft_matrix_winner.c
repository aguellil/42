/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_winner.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 15:10:34 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 22:16:06 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

/*
** Indicates the winner from a given matrix
** -2 : NULL has been passed as a parameter
** -1 : The game isn't finished
** 0 : It's a draw
** i : Player no i has won
*/

int			ft_matrix_winner(t_matrix *mat, t_options *opts)
{
	int	i;
	int	j;
	int	wn;

	i = opts->last_move_row;
	j = opts->last_move_column;
	wn = opts->win_nb;
	if (!mat)
		return (-2);
	if ((mat->data[i][j] != 0) \
		&& (ft_matrix_nb_ad_at(mat, i, j, 0) >= wn \
		|| ft_matrix_nb_ad_at(mat, i, j, 90) >= wn \
		|| ft_matrix_nb_ad_at(mat, i, j, 45) >= wn \
		|| ft_matrix_nb_ad_at(mat, i, j, 135) >= wn))
		return (mat->data[i][j]);
	if (opts->nb_moves == mat->n * mat->m)
		return (0);
	return (-1);
}
