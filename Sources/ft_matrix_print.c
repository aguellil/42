/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:22:57 by aguellil          #+#    #+#             */
/*   Updated: 2016/02/28 22:43:11 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "puissance4.h"

void	ft_matrix_print_nb(t_matrix *mat)
{
	int j;

	j = 1;
	while (j <= mat->m)
	{
		if (j < 100)
			ft_putstr(" ");
		if (j < 10)
			ft_putstr(" ");
		ft_putnbr(j);
		ft_putstr(" ");
		j++;
	}
	ft_putstr("\n");
}

void	ft_matrix_print(t_matrix *mat)
{
	int		i;
	int		j;

	i = 0;
	while (i < mat->n)
	{
		write(1, "|", 1);
		j = 0;
		while (j < mat->m)
		{
			if (mat->data[i][j] == 1)
				ft_putstr("\033[1;31m O \033[1;31m");
			else if (mat->data[i][j] == 2)
				ft_putstr("\033[1;34m O \033[1;34m");
			else
				ft_putstr("\033[0;m O \033[0;m");
			ft_putstr("\033[0;m|\033[0;m");
			j++;
		}
		ft_putstr("\n");
		i++;
	}
	ft_matrix_print_nb(mat);
}
