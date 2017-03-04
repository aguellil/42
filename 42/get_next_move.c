/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 03:50:31 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 08:30:58 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static t_move	*build_move(char *str)
{
	t_move		*move;

	if (!(move = malloc(sizeof(t_move))))
		return (NULL);
	if (str[0] == 'n')
	{
		if (!(move->domino = malloc(sizeof(t_move))))
		{
			free(move);
			return (NULL);
		}
		move->action = PLAY;
		move->domino->n1 = str[4];
		move->domino->n2 = str[6];
		move->domino->x = str[8];
		move->domino->y = str[10];
		move->domino->orientation = str[12];
		move->domino->direction = str[14];
	}
	else if (str[4] == 'd')
		move->action = DRAW;
	else if (str[4] == 's')
		move->action = SULK;
	return (move);
}

int				get_next_move(t_gamestate *gamestate)
{
	char	*str;
	t_move	*move;

	if (get_next_line(0, &str) < 1)
		return (-1);
	if (str[0] == 'e' || str['k'])
	{
		free(str);
		return (1);
	}
	else if (str[0] == 'n' || str[0] == 'p')
	{
		move = build_move(str);
		ft_lstadd(&(gamestate->movelist), ft_lstnew(move, sizeof(move)));
	}
	return (0);
}
