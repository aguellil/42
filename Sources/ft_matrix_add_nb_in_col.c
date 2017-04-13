/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_add_nb_in_col.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 23:19:47 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 19:29:10 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

/*
** Add a number in a matrix's column depending on the Connect Four's rules
*/

void	ft_matrix_add_nb_in_col(t_matrix *mat, int k, int j, t_options *opts)
{
	int	i;

	if (j < 0 || j >= mat->m)
		return ;
	i = mat->n - 1;
	while (i >= 0)
	{
		if (mat->data[i][j] == 0)
		{
			mat->data[i][j] = k;
			opts->nb_moves++;
			opts->last_move_row = i;
			opts->last_move_column = j;
			opts->winner = ft_matrix_winner(mat, opts);
			return ;
		}
		i--;
	}
}
