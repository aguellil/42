/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 23:22:33 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 23:36:09 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int			alum1_initialize(int argc, const char **argv, t_list **adata)
{
	int		fd;

	fd = 0;
	if (!ft_usage(argc) || !(*adata = ft_lstnew(NULL, 0)))
		return (1);
	if (argc == 1)
	{
		if (!parser(fd, adata))
			return (1);
	}
	else if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("./alum1: ");
		ft_putstr(argv[1]);
		ft_putstr(": No such file or directory\n");
		return (1);
	}
	if (fd > 0 && !parser(fd, adata))
	{
		close(fd);
		return (1);
	}
	if (argc == 2)
		close(fd);
	return (0);
}

void		alum1_process(t_list *data, int *aerror)
{
	int		current_player;
	int		nb_turns;

	if (*aerror == 1)
		return ;
	ai_implement_strategy(data);
	nb_turns = 1;
	while (data->content)
	{
		print_board(data);
		if (nb_turns == 1)
			current_player = human_ask_first_to_play(1);
		play_turn(data, current_player);
		if (((t_row *)data->content)->nb_matches == 0)
			remove_first(&data);
		nb_turns++;
		current_player = (current_player + 1) % 2;
	}
	remove_first(&data);
	ft_putstr("And the winner is ");
	if (current_player == MACHINE)
		ft_putstr("AI\n");
	else if (current_player == HUMAN)
		ft_putstr("HUMAN\n");
}

void		alum1_finalize(t_list *data, int *aerror)
{
	data = 0;
	aerror = 0;
	return ;
}

int			main(int argc, char const **argv)
{
	t_list	*data;
	int		error;

	error = alum1_initialize(argc, argv, &data);
	alum1_process(data, &error);
	alum1_finalize(data, &error);
	return (error);
}
