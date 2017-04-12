/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:56:51 by aguellil          #+#    #+#             */
/*   Updated: 2016/01/28 21:37:47 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** 1. Implementation
*/

/*
** 1.1 Iterative
*/

int	ft_atoi(const char *str)
{
	int	i;
	int	k;
	int	sign;

	k = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1 - 2 * (str[i] == '-');
	i = i + (1 - sign) / 2 + (str[i] == '+');
	while ('0' <= str[i] && str[i] <= '9')
		k = k * 10 + str[i++] - '0';
	return (k * sign);
}

/*
** 1.2 Recursive
*/

/*
**static int	ft_power(int k, size_t n)
**{
**	if (n == 0)
**		return (1);
**	return (k * ft_power(k, n - 1));
**}
***
**static int	ft_nb_of_digits(const char *str)
**{
**	if (*str == '+' || *str == '-')
**	{
**		if (*(str + 1) < '0' || *(str + 1) > '9')
**			return (0);
**		return (ft_nb_of_digits(str + 1));
**	}
**	if ('0' <= *str && *str <= '9')
**	{
**		if (*(str + 1) < '0' || *(str + 1) > '9')
**			return (1);
**		return (1 + ft_nb_of_digits(str + 1));
**	}
**	return (0);
**}
***
**int			ft_atoi(const char *str)
**{
**	if (*str == ' ' || *str == '\t' || *str == '\n' ||	\
**		*str == '\v' || *str == '\f' || *str == '\r')
**		return (ft_atoi(str + 1));
**	if (*str == '+' || *str == '-')
**	{
**		if (*(str + 1) < '0' || *(str + 1) > '9')
**			return (0);
**		return (((*str == '+') - (*str == '-')) * (ft_atoi(str + 1)));
**	}
**	if ('0' <= *str && *str <= '9')
**	{
**		if (*(str + 1) < '0' || *(str + 1) > '9')
**			return (*str - '0');
**		return (ft_power(10, ft_nb_of_digits(str) - 1) * (*str - '0') + \
**				ft_atoi(str + 1));
**	}
**	return (0);
**}
*/

/*
** 2. Manual
*/

/*
***
** ATOI(3)                  BSD Library Functions Manual                 ATOI(3)
***
** NAME
**      atoi, atoi_l -- convert ASCII string to integer
***
** LIBRARY
**      Standard C Library (libc, -lc)
***
** SYNOPSIS
**      #include <stdlib.h>
***
**      int
**      atoi(const char *str);
***
**      #include <xlocale.h>
***
**      int
**      atoi_l(const char *str, locale_t loc);
***
** DESCRIPTION
**      The atoi() function converts the initial portion of the string pointed
**      to by str to int representation.
***
**      It is equivalent to:
***
**            (int)strtol(str, (char **)NULL, 10);
***
**      While the atoi() function uses the current locale, the atoi_l() function
**      may be passed a locale directly. See xlocale(3) for more information.
***
** IMPLEMENTATION NOTES
**      The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
***
**      The strtol() and strtol_l() functions are recommended instead of atoi()
**      and atoi_l() functions, especially in new code.
***
** ERRORS
**      The function atoi() need not affect the value of errno on an error.
***
** SEE ALSO
**      atof(3), atol(3), strtod(3), strtol(3), strtoul(3), xlocale(3)
***
** STANDARDS
**      The atoi() function conforms to ISO/IEC 9945-1:1990 (``POSIX.1''),
**      ISO/IEC 9899:1990 (``ISO C90''), and ISO/IEC 9899:1999 (``ISO C99'').
***
** BSD                              June 4, 1993                             BSD
*/
