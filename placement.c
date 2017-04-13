/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 04:47:00 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 17:54:29 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static int		check_overflow(t_board *board, t_domino *domino)
{
	if ((unsigned int)domino->x > board->xsize || domino->x < 0)
		return (0);
	if ((unsigned int)domino->y > board->ysize || domino->y < 0)
		return (0);
	if (domino->orientation == HORIZONTAL && domino->direction == LEFT)
		if (((domino->x - 2) < 0)
			|| (((unsigned int)domino->x + 2) > board->xsize))
			return (0);
	if (domino->orientation == VERTICAL && domino->direction == UP)
		if (((domino->y - 2) < 0)
			|| (((unsigned int)domino->y + 2) > board->ysize))
			return (0);
	return (1);
}

static int		check_collision(t_board *board, t_domino *domino)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (board->map[domino->y][domino->x] != -1)
		return (0);
	if (domino->orientation == HORIZONTAL)
	{
		if (domino->direction == RIGHT)
			x = 1;
		else
			x = -1;
	}
	else
	{
		if (domino->direction == UP)
			y = -1;
		else
			y = 1;
	}
	if (board->map[domino->y + y][domino->x + x] != -1
		|| board->map[domino->y + 2 * y][domino->x + 2 * x] != -1)
		return (0);
	return (1);
}

int				is_move_valid(const t_move *move, const t_gamestate *gamestate)
{
	char	**map;

	map = gamestate->board->map;
	if (!check_overflow(gamestate->board, move->domino))
		return (0);
	if (!check_collision(gamestate->board, move->domino))
		return (0);
	return (1);
}
