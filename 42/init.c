/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 03:17:04 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 17:40:46 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

static void	init_player(t_player **aaplayer, int *aerror)
{
	if (aaplayer == 0 || aerror == 0 || *aerror != 0)
		return ;
	if (!(*aaplayer = (t_player *)malloc(sizeof(t_player))))
	{
		*aerror = 1;
		return ;
	}
	if (!((*aaplayer)->hand = (t_list *)malloc(sizeof(t_list))))
	{
		*aerror = 1;
		free(*aaplayer);
	}
	return ;
}

static void	init_board(t_board **aaboard, int *aerror)
{
	if (aaboard == 0 || aerror == 0 || *aerror != 0)
		return ;
	if (!(*aaboard = (t_board *)malloc(sizeof(t_board))))
	{
		*aerror = 1;
		return ;
	}
	if (!((*aaboard)->map = (char **)malloc(sizeof(char *))))
	{
		*aerror = 1;
		free(*aaboard);
		return ;
	}
	if (!((*aaboard)->extremities = (t_list *)malloc(sizeof(t_list))))
	{
		*aerror = 1;
		free((*aaboard)->map);
		free(*aaboard);
	}
	return ;
}

static void	init_movelist(t_list **aamovelist, int *aerror)
{
	if (aamovelist == 0 || aerror == 0 || *aerror != 0)
		return ;
	if (!(*aamovelist = (t_list *)malloc(sizeof(t_list))))
	{
		*aerror = 1;
		return ;
	}
	*aamovelist = NULL;
	return ;
}

static void	init_gamestate(t_gamestate *ags, int *aerror)
{
	if (ags == 0 || aerror == 0 || *aerror != 0)
		return ;
	init_player(&(ags->player), aerror);
	init_player(&(ags->opponent), aerror);
	init_board(&(ags->board), aerror);
	init_movelist(&(ags->movelist), aerror);
	if (!(ags->opponent) || !(ags->board) || !(ags->movelist))
	{
		*aerror = 1;
		free(ags->player->hand);
		free(ags->player);
	}
	if (!(ags->board) || !(ags->movelist))
	{
		*aerror = 1;
		free(ags->opponent->hand);
		free(ags->opponent);
	}
	if (!(ags->movelist))
	{
		*aerror = 1;
		free(ags->board->map);
		free(ags->board->extremities);
		free(ags->board);
	}
}

int			init(t_gamestate *agamestate)
{
	char	*input;
	int		error;

	init_gamestate(agamestate, &error);
	if (error != 0)
		return (-1);
	if (get_next_line(0, &input) < 1)
		return (-1);
	while (vm_input_parse(input, agamestate) != 1)
	{
		free(input);
		get_next_line(0, &input);
		if (get_next_line(0, &input) < 1)
			return (-1);
	}
	free(input);
	return (0);
}
