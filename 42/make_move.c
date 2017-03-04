/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 08:40:30 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 18:16:33 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_move	*make_move(t_extremity *extremity, t_domino *child)
{
	t_move	*move;

	if (!(move = malloc(sizeof(t_move))))
		return (NULL);
	move->action = PLAY;
	move->parent = extremity;
	move->domino = child;
	child->x += extremity->x;
	child->y += extremity->y;
	return (move);
}
