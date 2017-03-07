/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 04:33:38 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 08:02:26 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void	ft_game_initialize(t_matrix **amat, t_options **aopts, int *aerror)
{
	if (aerror == 0)
		return ;
	*aerror = 0;
	(*aopts)->nb_moves = 0;
	(*aopts)->last_move_row = -1;
	(*aopts)->last_move_column = -1;
	(*aopts)->winner = -1;
	(*aopts)->current_player = 1 + rand() % ((*aopts)->nb_players);
	*amat = ft_matrix_create((*aopts)->height, (*aopts)->width, 0);
	if (!(*amat))
		*aerror = -1;
	return ;
}

static void	ft_game_finalize(t_matrix *amat, t_options *aopts)
{
	if (opts->winner == 0)
	{
		ft_putstr("It's a draw!\n");
		return ;
	}
	if (opts->winner == 1)
		ft_putstr("IA ");
	else
		ft_putstr("Player ");
	ft_putstr("has won.\n");
	ft_matrix_free(mat);
	return ;
}

static int	ft_game_profondeur(t_matrix *mat)
{
	if (mat->n <= 7 && mat->m <= 7)
		return (7);
	if (mat->n <= 15 && mat->m <= 15)
		return (5);
	if (mat->n <= 100 && mat->m <= 100)
		return (3);
	return (1);
}

static int	ft_game_process(t_matrix *mat, t_options *opts, int *aerror)
{
	int move;
	int profondeur;
	
	profondeur = ft_game_profondeur(mat);
	ft_matrix_print(mat);
	while (opts->winner == -1)
	{
		if (opts->current_player == 1)
			ft_ia(mat, profondeur, opts);
		else
		{
			if ((move = ft_game_read_move_player(mat)) == -1)
			{
				*aerror = -1;
				return ;
			}
			ft_matrix_add_nb_in_col(mat, opts->current_player, move, opts);
		}
		ft_putstr("\n");
		ft_matrix_print(mat);
		opts->current_player = opts->current_player % opts->nb_players + 1;
	}
	return ;
}

int			ft_game(t_options *opts)
{
	t_matrix	*matrix;
	int			error;

	ft_game_initialize(&mat, &opts, &error);
	ft_game_process(mat, opts, &error);
	ft_game_finalize(mat, opts, error);
	return (0);
}
