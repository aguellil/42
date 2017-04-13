/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_store.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:38:27 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 22:03:52 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

/*
** set player and opponent id.
*/

void		vm_input_store_player(char *input, t_gamestate *agamestate)
{
	if (input == NULL || agamestate == NULL)
		return ;
	agamestate->player->id = input[9] - '0';
	agamestate->opponent->id = (agamestate->player->id == 1) ? 2 : 1;
	free(input);
}

void		vm_input_store_board(char *input, t_gamestate *agamestate)
{
	char		*ptr;

	if (input == NULL || agamestate == NULL)
	{
		return ;
	}
	ptr = input + 6;
	agamestate->board->xsize = ft_atoi(ptr);
	while (*ptr != ':')
		ptr++;
	ptr++;
	agamestate->board->ysize = ft_atoi(ptr);
	free(input);
	return ;
}

int			vm_input_store_hand(char *input, t_gamestate *agamestate)
{
	t_domino	*adomino;
	t_list		*anode;
	size_t		size;

	if (input == NULL || agamestate == NULL)
	{
		return (-1);
	}
	size = input[9] - '0';
	free(input);
	while (size)
	{
		if (get_next_line(0, &input) < 1)
			return (-1);
		if (!(adomino = (t_domino *)malloc(sizeof(t_domino)))
			|| !(anode = ft_lstnew(adomino, sizeof(t_domino))))
			return (-1);
		ft_lstadd(&(agamestate->player->hand), anode);
		adomino->n1 = input[6] - '0';
		adomino->n2 = input[8] - '0';
		free(input);
		size--;
	}
	return (1);
}

int			vm_input_store_playmove(char *input, t_gamestate *agamestate)
{
	t_move		*move;
	t_domino	*domino;

	if (!(move = malloc(sizeof(t_move)))
		|| !(domino = make_domino(input)))
	{
		if (move)
			free(move);
		return (-1);
	}
	move->action = PLAY;
	move->domino = domino;
	free(input);
	if (get_next_line(0, &input) < 1)
		return (-1);
	move->player = input[2];
	free(input);
	apply_move(agamestate, move);
	return (1);
}

int			vm_input_store_move(char *input, t_gamestate *agamestate)
{
	t_move	*move;

	if (!(move = malloc(sizeof(t_move))))
		return (-1);
	move->player = input[2] - '0';
	if (!ft_strncmp(input + 4, "draw", 4))
		move->action = DRAW;
	else if (!ft_strncmp(input + 4, "sulk", 4))
		move->action = SULK;
	else if (!ft_strncmp(input + 4, "put", 3))
		(void)0;
	else
		move->action = SULK;
	ft_lstadd(&(agamestate->movelist), ft_lstnew(move, sizeof(move)));
	free(input);
	return (1);
}
