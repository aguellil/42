/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguellil <yguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:27:39 by yguellil          #+#    #+#             */
/*   Updated: 2016/12/09 04:47:43 by yguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Count the numeral into an int, sign include.
*/

static int		ft_count_numeral(int n)
{
	unsigned int	len_n;

	if (n == 0)
		return (1);
	len_n = 0;
	if (n < 0)
		len_n++;
	while (n != 0)
	{
		len_n++;
		n = (n / 10);
	}
	return (len_n);
}

/*
** Create a string from an int.
*/

static void		ft_str_from_int(char *str, int n, unsigned int len)
{
	int		sign;

	sign = 0;
	if (n < 0)
		sign = -1;
	else
		sign = 1;
	str[len] = '\0';
	while (len != 0)
	{
		if (len == 1 && sign == -1)
			str[0] = '-';
		else
		{
			str[len - 1] = (n % 10) * sign + '0';
			n = n / 10;
		}
		len--;
	}
	return ;
}

/*
** Return the string of characters correspond to an int.
*/

char			*ft_itoa(int n)
{
	char			*str_int;
	unsigned int	len_n;

	len_n = ft_count_numeral(n);
	str_int = (char*)malloc(sizeof(*str_int) * (len_n + 1));
	if (str_int == NULL)
		return (NULL);
	ft_str_from_int(str_int, n, len_n);
	return (str_int);
}
