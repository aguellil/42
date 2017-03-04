/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 00:49:17 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 17:49:07 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void	announce_play(const t_move *move)
{
	if (move->action == PLAY)
	{
		ft_putstr("put:");
		ft_putnbr(move->domino->n1);
		ft_putstr(":");
		ft_putnbr(move->domino->n2);
		ft_putstr(":");
		ft_putnbr(move->domino->y);
		ft_putstr(":");
		ft_putnbr(move->domino->x);
		ft_putstr(":");
		ft_putnbr(move->domino->orientation);
		ft_putstr(":");
		ft_putnbr(move->domino->direction);
		ft_putstr("\n");
	}
	else if (move->action == DRAW)
		ft_putstr("draw\n");
	else if (move->action == SULK)
		ft_putstr("sulk\n");
}

static void	commit_play(const t_move *move, t_gamestate *gamestate)
{
	int	n;

	n = -1;
	gamestate->board->map[move->domino->y][move->domino->x] = move->domino->n1;
	if (move->domino->orientation == VERTICAL)
	{
		if (move->domino->direction == UP)
			n = +1;
		gamestate->board->map[move->domino->y + n * 1][move->domino->x] = -2;
		gamestate->board->map[move->domino->y + n * 2]
		[move->domino->x] = move->domino->n2;
	}
	else
	{
		if (move->domino->direction == RIGHT)
			n = +1;
		gamestate->board->map[move->domino->y][move->domino->x + n * 1] = -2;
		gamestate->board->map[move->domino->y]
		[move->domino->x + n * 2] = move->domino->n2;
	}
}

static void	get_drawn_card(t_list **hand)
{
	char		*str;
	t_domino	*domino;
	t_list		*alink;

	if (get_next_line(0, &str) < 0)
		return ;
	if (str[0] == 'k')
		return ;
	if (!(domino = malloc(sizeof(t_domino))))
		return ;
	if (!(alink = ft_lstnew(domino, sizeof(t_domino))))
	{
		free(domino);
		return ;
	}
	domino->n1 = str[7];
	domino->n2 = str[9];
	ft_lstadd(hand, alink);
	free(str);
}

void		play_move(const t_move *move, t_gamestate *gamestate, int silent)
{
	if (!silent)
		announce_play(move);
	if (move->action == PLAY)
		commit_play(move, gamestate);
	else if (move->action == DRAW)
		get_drawn_card(&(gamestate->player->hand));
	else if (move->action == SULK)
		(void)0;
}

void		cancel_move(const t_move *move, t_gamestate *gamestate)
{
	int	n;

	n = -1;
	gamestate->board->map[move->domino->y][move->domino->x] = -1;
	if (move->domino->orientation == VERTICAL)
	{
		if (move->domino->direction == UP)
			n = +1;
		gamestate->board->map[move->domino->y + n * 1][move->domino->x] = -1;
		gamestate->board->map[move->domino->y + n * 2]
		[move->domino->x] = -1;
	}
	else
	{
		if (move->domino->direction == RIGHT)
			n = +1;
		gamestate->board->map[move->domino->y][move->domino->x + n * 1] = -1;
		gamestate->board->map[move->domino->y]
		[move->domino->x + n * 2] = -1;
	}
}
