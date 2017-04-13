/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puissance4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 17:32:35 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 23:15:06 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

static int	ft_puissance4_initialize(t_options **aopts, char **argv)
{
	*aopts = (t_options *)malloc(sizeof(t_options));
	if (!(*aopts))
		return (-1);
	(*aopts)->height = ft_atoi(argv[1]);
	(*aopts)->width = ft_atoi(argv[2]);
	(*aopts)->height_max = 999;
	(*aopts)->width_max = 999;
	(*aopts)->win_nb = 4;
	(*aopts)->winner = -1;
	(*aopts)->nb_players = 2;
	(*aopts)->current_player = -1;
	(*aopts)->nb_moves = 0;
	(*aopts)->last_move_row = -1;
	(*aopts)->last_move_column = -1;
	srand(time(NULL));
	return (0);
}

static void	ft_puissance4_finalize(t_options *opts)
{
	free(opts);
	return ;
}

int			main(int argc, char **argv)
{
	t_options	*opts;

	if (argc == 3)
	{
		if (!ft_puissance4_arg(argv))
		{
			ft_putstr("Error: arg\n");
			return (-1);
		}
		if (ft_puissance4_initialize(&opts, argv) == -1)
		{
			ft_putstr("Error: malloc\n");
			return (-1);
		}
		if (ft_game(opts) == -1)
			return (-1);
		ft_puissance4_finalize(opts);
	}
	else
		ft_putstr("Error: 2 arguments needed (height width)\n");
	return (0);
}
