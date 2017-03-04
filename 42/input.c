/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 03:17:04 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/04 09:02:14 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

char			vm_input_typeof(char *input)
{
	char	c0;
	char	c1;
	char	c5;

	if (input == 0)
		return (0);
	c0 = input[0];
	c1 = input[1];
	c5 = input[5];
	return ((c0 == 'p') * \
			('P' * (c1 == 'l') + 'D' * (c5 == ':') + 'N' * (c5 == 's')) + \
			'G' * (c0 == 'g' && c1 == 'o') + 'B' * (c0 == 'b'));
}

static int		vm_input_store_player(char *input, t_gamestate *agamestate)
{
	if (input == 0 || agamestate == 0)
		return (-1);
	agamestate->player->id = input[9] - '0';
	agamestate->opponent->id = '1' + '2' - agamestate->player->id;
	return (0);
}

static int		vm_input_store_board(char *input, t_gamestate *agamestate)
{
	if (input == 0 || agamestate == 0)
		return (-1);
	input = input + 6;
	agamestate->board->ysize = ft_atoi(input);
	while (*input != ':')
		input++;
	input++;
	agamestate->board->xsize = ft_atoi(input);
	return (0);
}

static int		vm_input_store_domino(char *input, t_gamestate *agamestate)
{
	t_domino	*adomino;
	t_list		*alink;

	if (input == 0 || agamestate == 0)
		return (-1);
	if (!(adomino = (t_domino *)malloc(sizeof(t_domino))))
		return (-1);
	if (!(alink = ft_lstnew(adomino, sizeof(t_domino))))
	{
		free(adomino);
		return (-1);
	}
	ft_lstadd(&(agamestate->player->hand), alink);
	return (0);
}

int				vm_input_parse(char *input, t_gamestate *agamestate)
{
	char		type;

	if (input == 0 || agamestate == 0)
		return (-1);
	type = vm_input_typeof(input);
	if (type == 'P')
		vm_input_store_player(input, agamestate);
	if (type == 'B')
		vm_input_store_board(input, agamestate);
	if (type == 'D')
		vm_input_store_domino(input, agamestate);
	if (type == 'G')
		return (1);
	if (type == 'N')
		return (0);
	return (0);
}
