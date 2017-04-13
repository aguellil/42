/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_write_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 16:19:05 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 18:09:17 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	player_write_fd(t_player *player, int fd)
{
	if (player == 0)
		return ;
	ft_putstr_fd("Id: ", fd);
	ft_putnbr_fd(player->id, fd);
	ft_putstr_fd("\nScore: ", fd);
	ft_putnbr_fd((int)player->score, fd);
	ft_putstr_fd("\nHand:\n", fd);
	while (player->hand)
	{
		domino_write_fd(player->hand->content, fd);
		ft_putchar_fd('\n', fd);
		player->hand = player->hand->next;
	}
	return ;
}
