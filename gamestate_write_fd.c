/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestate_write_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:44:51 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 18:16:55 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	gamestate_write_fd(t_gamestate *gamestate, int fd)
{
	ft_putstr_fd("Scoredif: ", fd);
	ft_putnbr_fd(gamestate->scoredif, fd);
	ft_putstr_fd("\n\nPlayer:\n", fd);
	player_write_fd(gamestate->player, fd);
	ft_putstr_fd("\nOpponent:\n", fd);
	player_write_fd(gamestate->opponent, fd);
	ft_putstr_fd("\nBoard:\n", fd);
	board_write_fd(gamestate->board, fd);
}
