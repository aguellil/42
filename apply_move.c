/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:31:08 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 21:13:18 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void		apply_move(t_gamestate *agamestate, t_move *move)
{
	ft_lstadd(&(agamestate->movelist), ft_lstnew(move, sizeof(move)));
	remove_domino_from_hand(move->domino, move->player, agamestate);
	commit_play(move, agamestate);
	update_extremity(move, agamestate);
}

void		remove_domino_from_hand(t_domino *d, int p, t_gamestate *gs)
{
	t_list		*node;
	t_list		*prec;
	t_list		*next;
	t_list		**hand;
	t_domino	*domino;

	hand = (p == gs->player->id) ? &(gs->player->hand) : &(gs->opponent->hand);
	prec = NULL;
	node = *hand;
	while (node)
	{
		next = node->next;
		domino = node->content;
		if ((domino->n1 == d->n1) || (domino->n2 == d->n2))
		{
			free(domino);
			free(node);
			if (prec)
				prec->next = next;
			else
				*hand = prec;
		}
		node = next;
	}
	return ;
}
