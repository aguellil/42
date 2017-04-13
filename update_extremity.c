/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_extremity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 21:48:47 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 23:25:00 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

/*
** return the closest extremity.
** We know the domino's root is exactly one tile away.
*/

static t_extremity	*find_closest_extremity(t_domino *domino, t_list *list)
{
	t_extremity	*cur;

	cur = NULL;
	while (list)
	{
		cur = list->content;
		if (abs((int)(domino->x - cur->x)) == 1 || \
			abs((int)(domino->y - cur->y)))
			return (cur);
		list = list->next;
	}
	return (cur);
}

static void			delete_extremity(t_list **list, t_extremity *extremity)
{
	t_list	*prec;
	t_list	*node;
	t_list	*next;

	prec = NULL;
	node = *list;
	while (node)
	{
		next = node->next;
		if (node->content == extremity)
		{
			free(node->content);
			free(node);
			if (prec)
				prec->next = next;
			else
				*list = next;
		}
		node = next;
	}
}

static void			update_extremity_double(t_gamestate *gamestate, t_domino *d)
{
	if (!gamestate->board->extremities)
	{
		ft_lstadd(&(gamestate->board->extremities),
				ft_lstnew(make_extremity_from_root(d),
							sizeof(t_extremity)));
		ft_lstadd(&(gamestate->board->extremities),
				ft_lstnew(make_extremity_from_tip(d),
							sizeof(t_extremity)));
	}
}

/*
** update extremity list from the move to the gamestate.
*/

void				update_extremity(const t_move *move, t_gamestate *gamestate)
{
	t_domino	*d;
	t_extremity	*prec;

	d = move->domino;
	prec = find_closest_extremity(move->domino, gamestate->board->extremities);
	if (!prec)
	{
		d->n1 = d->n1 ^ d->n2;
		d->n2 = d->n1 ^ d->n2;
		d->n1 = d->n1 ^ d->n2;
		prec = find_closest_extremity(move->domino,
									gamestate->board->extremities);
	}
	if (move->domino->n1 != move->domino->n2)
		ft_lstadd(&(gamestate->board->extremities),
				ft_lstnew(make_extremity_from_root(d), sizeof(t_extremity)));
	else
		update_extremity_double(gamestate, d);
	if (prec)
		delete_extremity(&(gamestate->board->extremities), prec);
}
