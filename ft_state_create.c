/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguellil <aguellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 12:51:40 by aguellil          #+#    #+#             */
/*   Updated: 2017/03/05 12:59:26 by aguellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domino.h"

t_state	*ft_state_create(void)
{
	t_state	*astate;

	if (!(astate = (t_state *)malloc(t_state)))
		return (0);
	return (astate);
}
