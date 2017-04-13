/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 06:12:31 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 19:56:23 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void		clean_map(t_board *board)
{
	size_t	x;

	x = 0;
	while (x < board->xsize)
	{
		if (board->map[x])
			free(board->map[x]);
		x++;
	}
	free(board->map);
}

/*
** clear the list from memory, but not its
** content, as it is already referenced from the main moveset.
*/

void		clean_extremities(t_board *board)
{
	t_list	*node;
	t_list	*next;

	node = board->extremities;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

/*
** clear all the dominoes in the hand of the player.
*/

static void	clean_hand(t_list *hand)
{
	t_list *node;
	t_list *next;

	node = hand;
	while (node)
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
	}
}

/*
** clear from memory all moves (and their dominoes).
*/

static void	clean_movelist(t_list *movelist)
{
	t_list	*node;
	t_list	*next;

	node = movelist;
	while (node)
	{
		next = node->next;
		free(((t_move*)node->content)->domino);
		free(node->content);
		free(node);
		node = next;
	}
}

void		cleanup(const t_gamestate *gamestate)
{
	clean_map(gamestate->board);
	clean_extremities(gamestate->board);
	clean_hand(gamestate->player->hand);
	clean_hand(gamestate->opponent->hand);
	free(gamestate->player);
	free(gamestate->opponent);
	free(gamestate->board);
	clean_movelist(gamestate->movelist);
}
