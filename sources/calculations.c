/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 13:40:24 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/26 21:59:00 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_min_square_side(int nb_tetriminos)
{
	int		nb_unit;
	int		min_square_side;

	nb_unit = 0;
	min_square_side = 2;
	nb_unit = nb_tetriminos * 4;
	while (nb_unit > (min_square_side * min_square_side))
		min_square_side++;
	return (min_square_side);
}

unsigned char	ft_pow(unsigned char nb, int pow)
{
	unsigned char		result;

	result = 1;
	if (pow == 0)
		result = 1;
	while (pow >= 1)
	{
		result = result * nb;
		pow--;
	}
	return (result);
}

unsigned char	ft_max(unsigned char c1, unsigned char c2)
{
	return ((c1 < c2) ? c2 : c1);
}

char			ft_focus_first_bit(unsigned char bin1, unsigned char bin2)
{
	char	sign;
	char	i;
	char	diff;

	sign = 1;
	diff = bin2 - bin1;
	if (diff > 0)
		sign = -1;
	else
		diff = -diff;
	if (diff < 12)
		i = 1;
	else
		i = 2;
	return (i * sign);
}

int				ft_search_last_one_in_bin(unsigned char bin, int nb_bits)
{
	int		position_of_last_one;

	if (bin == 0)
		return (bin);
	position_of_last_one = nb_bits;
	while ((bin % 2) == 0)
	{
		bin = bin / 2;
		position_of_last_one--;
	}
	return (position_of_last_one);
}
