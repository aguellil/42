/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 03:17:04 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 21:50:12 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

/*
** allocate player structure
*/

int	init_player(t_player **aaplayer)
{
	if (aaplayer == NULL)
		return (0);
	if (!(*aaplayer = malloc(sizeof(t_player))))
		return (0);
	(*aaplayer)->hand = NULL;
	(*aaplayer)->score = 0;
	ft_putstr_fd("init player successfull.\n", 2);
	return (1);
}

/*
** allocate board structure
** EXCEPT MAP.
*/

int	init_board(t_board **aaboard)
{
	if (aaboard == 0)
		return (0);
	if (!(*aaboard = malloc(sizeof(t_board))))
		return (0);
	(*aaboard)->extremities = NULL;
	(*aaboard)->ysize = 0;
	(*aaboard)->xsize = 0;
	(*aaboard)->map = NULL;
	ft_putstr_fd("init board successfull.\n", 2);
	return (1);
}

int	init_map(t_board *aaboard)
{
	int	x;
	int	y;

	if (!(aaboard->map = malloc(sizeof(char*) * aaboard->ysize)))
	{
		free(aaboard);
		return (0);
	}
	y = 0;
	while ((unsigned int)y < aaboard->ysize)
	{
		if (!(aaboard->map[y] = malloc(sizeof(char) * aaboard->xsize)))
		{
			aaboard->ysize = y - 1;
			clean_map(aaboard);
			return (0);
		}
		x = -1;
		while ((size_t)++x < aaboard->xsize)
			aaboard->map[y][x] = -1;
		y++;
	}
	ft_putstr_fd("map init successfull.\n", 2);
	return (1);
}

int	init_movelist(t_list **aamovelist)
{
	if (aamovelist == 0)
		return (0);
	if (!(*aamovelist = (t_list *)malloc(sizeof(t_list))))
		return (0);
	*aamovelist = NULL;
	ft_putstr_fd("init movelist successfull.\n", 2);
	return (1);
}

int	init_gamestate(t_gamestate *ags)
{
	if (ags == 0)
		return (-1);
	if (!init_player(&(ags->player))
		|| !init_player(&(ags->opponent))
		|| !init_board(&(ags->board))
		|| !init_movelist(&(ags->movelist)))
		return (0);
	return (1);
}

/*
** ...end of init_gamestate: probably need reimplementation
**	if (!(ags->opponent) || !(ags->board) || !(ags->movelist))
**	{
**		free(ags->player->hand);
**		free(ags->player);
**	}
**	if (!(ags->board) || !(ags->movelist))
**	{
**		*aerror = 1;
**		free(ags->opponent->hand);
**		free(ags->opponent);
**	}
**	if (!(ags->movelist))
**	{
**		*aerror = 1;
**		free(ags->board->map);
**		free(ags->board->extremities);
**		free(ags->board);
**	}
*/
