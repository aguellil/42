/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_domino_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:36:45 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:58:15 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <domino.h>

void	ft_domino_add(t_domino *adomino, t_domino **adominoes)
{
	if (adominoes == 0 || adomino == 0)
		return ;
	adomino->next = *adominoes;
	*adominoes = adomino;
	return ;
}
