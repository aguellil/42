/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:52:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 18:32:13 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int	main(void)
{
	t_gamestate		gamestate;
	int				gameover;
	t_move			*move;

	init(&gamestate);
	gameover = 0;
	while (!gameover)
	{
		move = select_best_move(&gamestate);
		write(2, "BUG", 3);
		ft_lstadd(&(gamestate.movelist), ft_lstnew(move, sizeof(move)));
		play_move(move, &gamestate, 0);
		gameover = get_next_move(&gamestate);
	}
	cleanup(&gamestate);
}
