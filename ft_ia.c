/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnguyen <mnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 19:28:50 by mnguyen           #+#    #+#             */
/*   Updated: 2016/02/28 22:06:48 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_matrix_ret_nb_in_col(t_matrix *mat, int j)
{
	int i;

	i = 0;
	while (i < mat->n)
	{
		if (mat->data[i][j] != 0)
		{
			mat->data[i][j] = 0;
			return ;
		}
		i++;
	}
}

int		ft_eval(t_matrix *mat, t_options *opts, int profondeur)
{
	if (ft_matrix_winner(mat, opts) == 1)
		return (100 - (7 - profondeur));
	else if (ft_matrix_winner(mat, opts) == 2)
		return (-100 + (7 - profondeur));
	else
		return (0);
}

int		ft_min(t_matrix *mat, int profondeur, t_options *opts)
{
	int min;
	int tmp;
	int j;

	if (profondeur == 0 || ft_matrix_winner(mat, opts) != -1)
		return (ft_eval(mat, opts, profondeur));
	min = 101;
	j = 0;
	while (j < mat->m)
	{
		if (mat->data[0][j] == 0)
		{
			ft_matrix_add_nb_in_col(mat, 2, j, opts);
			tmp = ft_max(mat, profondeur - 1, opts);
			if (tmp < min)
				min = tmp;
			opts->nb_moves -= 1;
			ft_matrix_ret_nb_in_col(mat, j);
		}
		j++;
	}
	return (min);
}

int		ft_max(t_matrix *mat, int profondeur, t_options *opts)
{
	int max;
	int tmp;
	int j;

	if (profondeur == 0 || ft_matrix_winner(mat, opts) != -1)
		return (ft_eval(mat, opts, profondeur));
	max = -101;
	j = 0;
	while (j < mat->m)
	{
		if (mat->data[0][j] == 0)
		{
			ft_matrix_add_nb_in_col(mat, 1, j, opts);
			tmp = ft_min(mat, profondeur - 1, opts);
			if (tmp > max)
				max = tmp;
			opts->nb_moves -= 1;
			ft_matrix_ret_nb_in_col(mat, j);
		}
		j++;
	}
	return (max);
}

void	ft_ia(t_matrix *mat, int profondeur, t_options *opts)
{
	int max;
	int maxj;
	int tmp;
	int j;

	max = -101;
	j = -1;
	while (++j < mat->m)
	{
		if (mat->data[0][j] == 0)
		{
			ft_matrix_add_nb_in_col(mat, 1, j, opts);
			tmp = ft_min(mat, profondeur - 1, opts);
			if (tmp > max || (tmp == max && (ft_abs((mat->m + 1) / 2 - (j + 1))
				- ft_matrix_nb_ad_at(mat, 0, j, 90) - 1 < ft_abs((mat->m
				+ 1) / 2 - (maxj + 1)) - ft_matrix_nb_ad_at(mat, 0, maxj, 90))))
			{
				max = tmp;
				maxj = j;
			}
			opts->nb_moves -= 1;
			ft_matrix_ret_nb_in_col(mat, j);
		}
	}
	ft_matrix_add_nb_in_col(mat, 1, maxj, opts);
}
