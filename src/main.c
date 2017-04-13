/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/04/24 18:39:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "hotrace.h"

int				main(int ac, char **av)
{
	t_htable	*table;
	char		print_buf[PRINT_SIZE];

	if (ac > 1)
	{
		ft_puterr(*av);
		ft_puterr(": too many arguments\n");
		return (EXIT_FAILURE);
	}
	table = new_table();
	ft_bzero(print_buf, PRINT_SIZE);
	if (!parsing(table, print_buf))
	{
		ft_puterr(*av);
		ft_puterr(": parsing failed\n");
		ft_putstr(print_buf);
		del_table(table);
		return (EXIT_FAILURE);
	}
	ft_putstr(print_buf);
	del_table(table);
	return (EXIT_SUCCESS);
}
