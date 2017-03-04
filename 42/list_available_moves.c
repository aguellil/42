/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_available_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 07:33:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 17:52:44 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_list			*list_possible_moves(t_extremity *extremity, t_domino *child)
{
	t_list *list;
	t_list *node;

	list = NULL;
	if (extremity->domino->orientation == HORIZONTAL)
	{
		list = list_horizontal_moves(extremity, child);
		node = list;
		while (node->next)
			node = node->next;
		node->next = list_horizontal_moves_flipped(extremity, child);
	}
	else if (extremity->domino->orientation == VERTICAL)
	{
		list = list_vertical_moves(extremity, child);
		node = list;
		while (node->next)
			node = node->next;
		node->next = list_vertical_moves_flipped(extremity, child);
	}
	return (list);
}

static void		triage_placeable_moves(t_list **l, t_list *m, t_gamestate *g)
{
	while (m)
	{
		if (is_move_valid((t_move*)m->content, g))
			ft_lstadd(l, ft_lstnew(m->content, sizeof(t_move)));
		else
			free(m->content);
		m = m->next;
	}
}

t_list			*list_available_moves(t_list *hand, t_gamestate *gamestate)
{
	t_list		*tlist;
	t_list		*list;
	t_list		*node;
	t_list		*next;

	list = NULL;
	while (hand)
	{
		node = gamestate->board->extremities;
		while (node)
		{
			tlist = list_possible_moves(node->content, hand->content);
			triage_placeable_moves(&list, tlist, gamestate);
			while (tlist)
			{
				next = tlist->next;
				free(tlist);
				tlist = next;
			}
			node = node->next;
		}
		hand = hand->next;
	}
	return (list);
}
