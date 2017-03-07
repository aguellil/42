/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 09:50:15 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 09:53:40 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	ft_char_write(char c, int fd)
{
	write(fd, &c, 1);
	return ;
}

void	ft_str_write(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	return ;
}
