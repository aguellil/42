/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 03:17:04 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 21:28:42 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int			init(t_gamestate *agamestate)
{
	char	*input;

	if (!init_gamestate(agamestate))
		return (-1);
	if (get_next_line(0, &input) < 1)
		return (-1);
	while (vm_input_parse(input, agamestate) == 1)
	{
		if (get_next_line(0, &input) < 1)
			return (-1);
	}
	ft_putstr_fd("vm input parsing successfull.\n", 2);
	init_map(agamestate->board);
	return (0);
}

/*
** while of init: input gets free'd in vm_input_parse.
*/
