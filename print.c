/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 16:43:36 by mbenjell          #+#    #+#             */
/*   Updated: 2017/04/02 23:11:58 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

void				print_board(t_list *data)
{
	static int		nb_matches;
	static t_row	*row;

	if (data->next && data->next->content)
		print_board(data->next);
	row = (t_row*)data->content;
	nb_matches = row->nb_matches;
	ft_putstr("\e[33m");
	while (nb_matches--)
		ft_putchar('|');
	ft_putchar('\n');
	ft_putstr("\e[0m");
}
