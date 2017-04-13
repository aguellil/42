/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 08:40:30 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 20:29:30 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_domino	*make_domino(char *input)
{
	t_domino	*domino;
	char		*p;

	if (!(domino = malloc(sizeof(t_domino))))
		return (NULL);
	p = input + 7;
	domino->x = ft_atoi(p);
	while (*p != ':')
		p++;
	domino->y = ft_atoi(p);
	while (*p != ':')
		p++;
	domino->orientation = p[1] - '0';
	domino->direction = p[2] - '0';
	domino->n1 = input[4] - '0';
	domino->n1 = input[6] - '0';
	return (domino);
}

t_move		*make_move(t_extremity *extremity, t_domino *child)
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
