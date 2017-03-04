/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 06:45:28 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 19:12:11 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"
#include "libft.h"

t_move		*select_best_move(t_gamestate *gamestate)
{
	t_move	*best_move;

	if (!(best_move = malloc(sizeof(t_move))))
		return (NULL);
	minimax(gamestate, DEPTH, 1, &best_move);
	return (best_move);
}

static int	max_player(t_gamestate *gamestate, unsigned int depth, t_move **p)
{
	t_list	*movelist;
	t_list	*node;
	t_move	*move;
	int		best_value;
	int		value;

	best_value = INT_MIN;
	movelist = list_available_moves(gamestate->player->hand, gamestate);
	node = movelist;
	while (node)
	{
		move = (t_move*)node->content;
		play_move(move, gamestate, 0);
		value = minimax(gamestate, depth - 1, 0, NULL);
		cancel_move(move, gamestate);
		best_value = (value > best_value) ? value : best_value;
		if (p)
			**p = *move;
		free(node->content);
		free(node);
		node = node->next;
	}
	return (best_value);
}

static int	min_player(t_gamestate *gamestate, unsigned int depth, t_move **p)
{
	t_list	*movelist;
	t_list	*node;
	t_move	*move;
	int		best_value;
	int		value;

	best_value = INT_MAX;
	movelist = list_available_moves(gamestate->opponent->hand, gamestate);
	node = movelist;
	while (node)
	{
		move = (t_move*)node->content;
		play_move(move, gamestate, 0);
		value = minimax(gamestate, depth - 1, 1, p);
		cancel_move(move, gamestate);
		best_value = (value < best_value) ? value : best_value;
		free(node->content);
		free(node);
		node = node->next;
	}
	return (best_value);
}

int			minimax(t_gamestate *g, unsigned int d, int maxplayer, t_move **p)
{
	int		best_value;

	if (d == 0 || 0)
		return (g->scoredif);
	if (maxplayer)
		best_value = max_player(g, d, p);
	else
		best_value = min_player(g, d, NULL);
	return (best_value);
}
