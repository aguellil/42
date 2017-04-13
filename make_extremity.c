/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_extremity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlegroux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 23:24:35 by tlegroux          #+#    #+#             */
/*   Updated: 2017/03/05 23:25:52 by tlegroux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_extremity			*make_extremity_from_root(t_domino *d)
{
	t_extremity	*ret;

	if (!(ret = malloc(sizeof(t_extremity))))
		return (NULL);
	ret->domino = d;
	ret->x = d->x;
	ret->y = d->y;
	ret->value = d->n1;
	return (ret);
}

t_extremity			*make_extremity_from_tip(t_domino *d)
{
	t_extremity	*ret;

	if (!(ret = malloc(sizeof(t_extremity))))
		return (NULL);
	ret->domino = d;
	if (d->orientation == VERTICAL)
	{
		ret->x = d->x;
		if (d->direction == UP)
			ret->y = d->y - 1;
		else
			ret->y = d->y + 1;
	}
	else
	{
		ret->y = d->y - 1;
		if (d->direction == LEFT)
			ret->y = d->x - 1;
		else
			ret->y = d->y + 1;
	}
	return (ret);
}
