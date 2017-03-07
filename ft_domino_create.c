/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_domino_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:10:17 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 11:29:39 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_domino *ft_domino_create(char n1, char n2, char o, char d)
{
	t_domino	*adomino;

	if (!(adomino = (t_domino *)malloc(sizeof(t_domino))))
		return (0);
	adomino->n1 = n1;
	adomino->n2 = n2;
	adomino->o = o;
	adomino->d = d;
	adomino->l = -1;
	adomino->c = -1;
	adomino->next = 0;
	return (adomino);
}
