/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:33:00 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 04:32:30 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			take_matches(t_list *data_row, int t)
{
	t_row	*row;

	row = (t_row*)data_row->content;
	if (t > 0 && t < 4 && row->nb_matches >= t)
		row->nb_matches -= t;
	else
		return (0);
	return (1);
}

void		play_turn(t_list *data, int player)
{
	int	nb_matches_to_take;

	nb_matches_to_take = 0;
	if (player == MACHINE)
	{
		nb_matches_to_take = ai_determine_matches_to_take(data);
		ft_putstr("AI");
	}
	else if (player == HUMAN)
	{
		nb_matches_to_take = human_ask_matches_to_take(data);
		ft_putstr("HUMAN");
	}
	ft_putstr(" takes ");
	ft_putnbr(nb_matches_to_take);
	if (nb_matches_to_take == 1)
		ft_putstr(" match ");
	else
		ft_putstr(" matches ");
	ft_putstr("on the last row.\n\n");
	take_matches(data, nb_matches_to_take);
	return ;
}
