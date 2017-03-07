/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_domino_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:26:54 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 12:00:12 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

void	ft_domino_free(t_domino *adomino)
{
	t_domino	*atmp;

	if (adomino == 0)
		return ;
	while (adomino)
	{
		atmp = adomino->next;
		free(adomino);
		adomino = atmp;
	}
	return ;
}
