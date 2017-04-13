/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_first_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 08:54:20 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 23:04:25 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static t_domino	*select_double(t_list **hand)
{
	t_list		*node[3];
	t_domino	*cur;

	node[0] = NULL;
	node[1] = *hand;
	while (node[1])
	{
		node[2] = node[1]->next;
		cur = (t_domino*)(node[1])->content;
		if (cur->n1 == cur->n2)
		{
			if (node[1])
				node[1]->next = node[2];
			else
				*hand = node[2];
			free(node[1]);
			return (cur);
		}
		else
		{
			node[0] = node[1];
			node[1] = node[2];
		}
	}
	return (NULL);
}

int				play_first_move(t_gamestate *gamestate)
{
	t_domino	*domino;
	t_move		*mov;

	if (!(domino = malloc(sizeof(t_domino))) || \
		!(mov = malloc(sizeof(t_move))))
	{
		if (domino)
			free(domino);
		return (-1);
	}
	domino = select_double(&(gamestate->player->hand));
	mov->domino = domino;
	mov->player = gamestate->player->id;
	mov->parent = NULL;
	mov->action = SULK;
	if (domino)
	{
		mov->action = PLAY;
		domino->orientation = HORIZONTAL;
		domino->direction = RIGHT;
		domino->x = gamestate->board->xsize / 2 - 1;
		domino->y = gamestate->board->ysize / 2;
	}
	play_move(mov, gamestate, 0);
	return (0);
}
