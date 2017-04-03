/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   human.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 03:33:23 by aguellil          #+#    #+#             */
/*   Updated: 2017/04/02 12:55:39 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	human_matches_answer_is_valid(char *answer, t_list *link)
{
	int	i;
	int	n;

	if (answer == 0 || *answer == '\n' || link == 0)
		return (0);
	i = 0;
	while (answer[i] != '\n')
	{
		if (!ft_isdigit(*answer))
			return (0);
		i++;
	}
	n = ft_atoi(answer);
	return (0 < n && n < 4 && n <= ((t_row *)link->content)->nb_matches);
}

static int	human_f2p_answer_is_valid(char *answer)
{
	if (answer == 0)
		return (0);
	if (!ft_strcmp(answer, "yes\n") || !ft_strcmp(answer, "y\n") || \
		!ft_strcmp(answer, "no\n") || !ft_strcmp(answer, "n\n"))
		return (1);
	return (0);
}

int			human_ask_matches_to_take(t_list *link)
{
	char	*answer;
	int		nb_matches_to_take;

	nb_matches_to_take = 0;
	answer = 0;
	while (!human_matches_answer_is_valid(answer, link))
	{
		free(answer);
		ft_putstr("How many matches do you want to take on the last row ? ");
		answer = input_read(0, "\n");
	}
	nb_matches_to_take = ft_atoi(answer);
	free(answer);
	return (nb_matches_to_take);
}

int			human_ask_first_to_play(int auth)
{
	char	*answer;
	char	player_chosen;

	if (auth == 0)
		return (HUMAN);
	answer = 0;
	while (!human_f2p_answer_is_valid(answer))
	{
		free(answer);
		ft_putstr("Do you want to play first ? ");
		answer = input_read(0, "\n");
	}
	player_chosen = HUMAN * (*answer == 'y') + MACHINE * (*answer == 'n');
	free(answer);
	return (player_chosen);
}
