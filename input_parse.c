/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 21:36:39 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 21:36:52 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

int				vm_input_parse(char *input, t_gamestate *agamestate)
{
	if (agamestate == NULL)
		return (-1);
	if (!input)
		return (-1);
	if (!(ft_strncmp(input, "player:n:", 9)))
		vm_input_store_player(input, agamestate);
	else if (!(ft_strncmp(input, "board:", 6)))
		vm_input_store_board(input, agamestate);
	else if (!(ft_strncmp(input, "pieces:n:", 9)))
		vm_input_store_hand(input, agamestate);
	else if (!(ft_strncmp(input, "new:", 4)))
		vm_input_store_playmove(input, agamestate);
	else if (!(ft_strncmp(input, "p:", 2)))
		vm_input_store_move(input, agamestate);
	else if (!(ft_strncmp(input, "go", 2)))
		return (0);
	else
	{
		ft_putstr_fd("Error: Invalid input parsed.\n", 2);
		ft_putstr_fd(input, 2);
		ft_putstr_fd("\n", 2);
		return (0);
	}
	return (1);
}
