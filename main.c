/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 23:52:01 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 22:41:59 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int		main(void)
{
	char			*buf;
	t_gamestate		gamestate;
	int				gameover;
	t_move			*move;

	init(&gamestate);
	ft_putstr_fd("ai init successfull\n", 2);
	if (gamestate.player->id == 1)
		play_first_move(&gamestate);
	gameover = 0;
	while (!gameover)
	{
		get_next_line(0, &buf);
		vm_input_parse(buf, &gamestate);
		free(buf);
		move = select_best_move(&gamestate);
		ft_lstadd(&(gamestate.movelist), ft_lstnew(move, sizeof(move)));
		play_move(move, &gamestate, 0);
		gameover = get_next_move(&gamestate);
	}
	cleanup(&gamestate);
}
