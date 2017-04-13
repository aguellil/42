/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 07:05:39 by yguellil          #+#    #+#             */
/*   Updated: 2017/01/26 22:31:20 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tetri		ft_initialize_tetri(t_tetri tetri, char letter)
{
	tetri.w = 0;
	tetri.x = 0;
	tetri.y = 0;
	tetri.z = 0;
	tetri.letter = letter;
	tetri.next = NULL;
	tetri.prev = NULL;
	return (tetri);
}

char		*ft_initialize_square(char *str, int len, int square_s)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (i % (square_s + 1) == square_s)
			str[i] = '\n';
		else
			str[i] = EMPTY;
		i++;
	}
	str[i] = '\0';
	return (str);
}
